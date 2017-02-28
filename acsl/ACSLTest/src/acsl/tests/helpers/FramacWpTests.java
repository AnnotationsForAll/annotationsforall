package acsl.tests.helpers;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import acsl.tests.TestOptions;
import acsl.tests.TestUtility;

import java.util.Arrays;
//import speedy.config.SpeedyOptions;
//import speedy.shared.core.IProblemListener;
//import speedy.core.ISubResultListener;
//import speedy.shared.core.Log;
//import speedy.tools.FramacWp;
//import speedy.tools.interfaces.ToolException;
//import speedy.tools.interfaces.ToolException.ToolFailure;








import framac.helpers.CommandLineProblemListener;
import framac.helpers.SpecificationChecker.CheckerResult;
import framac.helpers.ToolException;
import framac.helpers.ToolException.ToolFailure;
import framac.helpers.Utils;


/**
 * Modified FramacWP to add -pp-annot, and check expected results with assertions
 */
public class FramacWpTests {

    // Patterns to get results from different parts of the test
//    public static final Pattern PATTERN_behavior   = Pattern.compile("^\\[wp\\] \\[(?:Qed|Alt-Ergo)\\] Goal (?:.+)_(testValues_assert(?:.*)) : ([a-zA-Z]+)(?:.*)");
//    public static final Pattern PATTERN_vacuous    = Pattern.compile("^\\[wp\\] \\[(?:Qed|Alt-Ergo)\\] Goal (?:\\w+)_vacuous : ([a-zA-Z]+)(?:.*)");
//    public static final Pattern PATTERN_runFailure = Pattern.compile("^\\[wp\\] \\[(?:Qed|Alt-Ergo)\\] Goal (?:.+)_call_runFailure(\\d*)_pre : ([a-zA-Z]+)(?:.*)");
//    public static final Pattern PATTERN_runFailure2= Pattern.compile("^\\[wp\\] \\[(?:Qed|Alt-Ergo)\\] Goal (?:\\w+)_runFailure(\\d*)_call_(?:\\w+) : ([a-zA-Z]+)(?:.*)");
//    public static final Pattern PATTERN_runSuccess = Pattern.compile("^\\[wp\\] \\[(?:Qed|Alt-Ergo)\\] Goal (?:.+)_call_runSuccess_pre : ([a-zA-Z]+)(?:.*)");
//    public static final Pattern PATTERN_runSuccess2= Pattern.compile("^\\[wp\\] \\[(?:Qed|Alt-Ergo)\\] Goal (?:.+)_runSuccess_call_(?:.+) : ([a-zA-Z]+)(?:.*)");
    public static final Pattern PATTERN_behavior   = Pattern.compile("^\\[wp\\] \\[[^]]+\\] Goal (?:.+)_testValues(?:\\d*)_assert(?:.*) : ([a-zA-Z]+)(?:.*)");
    public static final Pattern PATTERN_vacuous    = Pattern.compile("^\\[wp\\] \\[[^]]+\\] Goal (?:\\w+)_vacuous : ([a-zA-Z]+)(?:.*)");
    public static final Pattern PATTERN_runFailure = Pattern.compile("^\\[wp\\] \\[[^]]+\\] Goal (?:.+)_call_runFailure(\\d*)_pre : ([a-zA-Z]+)(?:.*)");
    public static final Pattern PATTERN_runFailure2= Pattern.compile("^\\[wp\\] \\[[^]]+\\] Goal (?:\\w+)_runFailure(\\d*)_call_(?:\\w+) : ([a-zA-Z]+)(?:.*)");
    public static final Pattern PATTERN_runSuccess = Pattern.compile("^\\[wp\\] \\[[^]]+\\] Goal (?:.+)_call_runSuccess(?:\\d*)_pre : ([a-zA-Z]+)(?:.*)");
    public static final Pattern PATTERN_runSuccess2= Pattern.compile("^\\[wp\\] \\[[^]]+\\] Goal (?:.+)_runSuccess(?:\\d*)_call_(?:.+) : ([a-zA-Z]+)(?:.*)");
    public static final String  SUCCESS            = "Valid";
    
    
    public static final String IMPORT_PATH          = "IMPORT_PATH";
    public static final String IMPORT_WP_TIMEOUT    = "WP_TIMEOUT";
    public static final String DEFAULT_WP_TIMEOUT   = "60"; // In Seconds
    
    public TestOptions testOptions;
    public List<String> framac_args;
    public FramacWpTests(TestOptions testOptions, List<String> args, CommandLineProblemListener problemListener) {
        //super(options, problemListener);
        this.framac_args = args;
        this.testOptions = testOptions;
    }    
    
    protected List<String> getConstantArguments(){
        final File f = new File(testOptions.outputDir);
        f.mkdir();
        ArrayList<String> list = new ArrayList<String>() {{
                                    add("-wp");
                                    add("-wp-rte");
                                    add("-wp-print");
                                    add("-wp-out");
                                    add(f.getAbsolutePath().replace('\\','/'));
                                    add("-wp-model");
                                    add("Typed,var,int,float");
                                  }};
       return list;
    }
    protected List<String> buildSpecificCommandArgs() {
        List<String> result;
        /*try {
            result = super.buildSpecificCommandArgs();
        } catch (ToolException e) {
            return null;
        }*/
        result = getConstantArguments();
        result.add("-pp-annot");    // Redundant in Sodium
        result.add("-no-frama-c-stdlib");
        if(testOptions.x86_64) {
            result.add("-machdep");
            result.add("x86_64");
            result.add("-cpp-extra-args=\"-D__FC_MACHDEP_X86_64\""); //FIXME: Frama-c currently has a bug where it does not set machdep-based defines correctly
        }
        for(String path: TestUtility.getImportPaths()) {
            result.add("-cpp-extra-args=\"-I"+path+"\"");
        }
        
        // Set parallelism
        result.add("-wp-par");
        result.add("1");
        // Set Timeout
        String importTimeout = System.getenv(IMPORT_WP_TIMEOUT);
        result.add("-wp-timeout");
        result.add(importTimeout != null ? importTimeout : DEFAULT_WP_TIMEOUT);
        // set any other options the user might want
        result.addAll(Arrays.asList(testOptions.extraArguments));
        return result;
    }
    

    protected CheckerResult parseResultFromOutput(BufferedReader br) throws ToolException {
        String lineString = null;
        
        // Map of runFailure functions to status
        // False when only valid has been seen
        // True when any non-valid has been seen
        HashMap<String,Boolean> runFailureSuccess = new HashMap<String,Boolean>();
        boolean vacuousErrorFound = false;
        AssertionError error = null;
        try {
            // We want to read through all of the output, even if we find an error at some point
            while((lineString = br.readLine()) != null){
                System.out.println(lineString);
                
                // Check that command ran
                if (lineString.contains("command not found")) {
                    throw new ToolException(ToolFailure.CALL_FAILED,lineString, null);
                }
                if (lineString.contains("[kernel] user error:")) {
                    throw new ToolException(ToolFailure.MALFORMED_OR_MISSING_INPUT,lineString, null); 
                }
                // runFailure pre-condition checks
                Matcher valid = PATTERN_runFailure.matcher(lineString);
                if (valid.find()) {
                    if (valid.group(2).equals(SUCCESS)) {
                        if(!runFailureSuccess.containsKey(valid.group(1)))
                            runFailureSuccess.put(valid.group(1), Boolean.FALSE);
                    } else
                        runFailureSuccess.put(valid.group(1), Boolean.TRUE);
                }else if ((valid = PATTERN_runFailure2.matcher(lineString)).find()) {
                    if (valid.group(2).equals(SUCCESS) && error == null) { 
                        if(!runFailureSuccess.containsKey(valid.group(1)))
                            runFailureSuccess.put(valid.group(1), Boolean.FALSE);
                    } else
                        runFailureSuccess.put(valid.group(1), Boolean.TRUE);
                }
               // runSuccess pre-condition checks
                valid = PATTERN_runSuccess.matcher(lineString);
                if (valid.find()) {
                    if (!valid.group(1).equals(SUCCESS) && error == null) 
                        error = new AssertionError("A pre-condition that should have been valid was not: "+lineString);
                }else if ((valid = PATTERN_runSuccess2.matcher(lineString)).find()) {
                    if (!valid.group(1).equals(SUCCESS) && error == null) 
                        error = new AssertionError("A pre-condition that should have been valid was not: "+lineString);
                }
               // testValue behavior and contradiction checks
                valid = PATTERN_vacuous.matcher(lineString);
                if (valid.find()) {
                    vacuousErrorFound = true;
                    if (valid.group(1).equals(SUCCESS) && error == null) 
                        error = new AssertionError("A contradiction was found: " + lineString);
                } else if ((valid = PATTERN_behavior.matcher(lineString)).find()) {
//                    if (!valid.group(2).equals(SUCCESS)) {
//                        String root = valid.group(1);
//                        String nm = null;
//                        File f = new File("temp/typed/" + root + ".ergo");
//                        if (f.exists()) {
//                            String line = null;
//                            BufferedReader brr = new BufferedReader(new FileReader(f));
//                            while((line = brr.readLine()) != null){
//                                int k = line.indexOf("SpecsTests");
//                                if (k > 0) {
//                                    nm = line.substring(k);
//                                    k = nm.indexOf(")");
//                                    nm = nm.substring(0,k);
//                                    break;
//                                }
//                            }
//                            
//                        }
//                        if (error == null) {
//                            String msg = "A behavior did not succeed: " + lineString;
//                            if (nm != null) msg = msg + "\n" + nm;
//                            error = new AssertionError(msg);
//                        }
//                    }
                    // Else if here to exclude the contradiction test
                    if (!valid.group(1).equals(SUCCESS) && (error == null || vacuousErrorFound)) // Override vacuous failure for more descriptive failures
                        error = new AssertionError("A behavior did not succeed: " + lineString);
                }
            }
            if(error == null) {
                for(String key: runFailureSuccess.keySet()) {
                    if(!runFailureSuccess.get(key))
                        error = new AssertionError("A pre-condition in runFailure"+key+" that should not have been valid was.");
                }
            }
        } catch (IOException | NumberFormatException e) {
            throw new ToolException(ToolFailure.MALFORMED_OR_MISSING_OUTPUT, e);
        }
        if (error != null) throw error;
        if (!vacuousErrorFound) throw new AssertionError("The vacuous test is never reached");
        return CheckerResult.UNKNOWN_RESULT;
    }
    
    
    protected List<String> getFullProcessCmdArgs() throws ToolException {
        List<String> commandArgs = new ArrayList<String>();
        commandArgs.add(Utils.mapSystemFilenameToPosixFilename(testOptions.framac_path));
        // user will have to pass "-cpp-command" if needed.
        commandArgs.addAll(buildSpecificCommandArgs());
        commandArgs.addAll(this.framac_args);
        return commandArgs;
    }
    
    public CheckerResult runTool() throws ToolException{
        List<String> cmdArgs = getFullProcessCmdArgs();
        boolean completed = false;
        int ev = 0;
        long timeoutInSeconds = 300; // 5 mins 
        try {
            
            Process process = Utils.startFramaCProcess(cmdArgs, null, testOptions);
            
            try (BufferedReader br = getBufferedInputReader(process)) {
                Thread.sleep(1); // FIXME - should do something better - problem is the buffer fills up and blocks, but it can be empty right at the start

                CheckerResult result = parseResultFromOutput(br);
                            // Might throw a ToolException
                completed = true;
                
                //toolLog(SpeedyOptions.PROGRESS, "Tool result:", result); TODO: check if we want to print
                
                return result;
            } finally {
                long now = System.currentTimeMillis();
                long timeoutInMillis = 1000L * timeoutInSeconds;
                long finish = now + timeoutInMillis;
                while(isProcessAlive(process) && (System.currentTimeMillis() < finish)){
                    Thread.sleep(10);
                }
                if(isProcessAlive(process)){
                    // process is still alive after 5 mins.
                    process.destroy();
                    ev = -1;
                }else{
                    ev = process.exitValue();
                }
                            
                //if (options.verbose >= SpeedyOptions.PROGRESS) {
                    System.out.println(String.format("Processing with framac %s.", (ev > 1 ? "tool failed" : (completed && ev == 0) ?"complete":"had errors")));
                //}
                //if(completed){
                   // cleanup();
                //}
                if(ev == -1){
                    throw new ToolException(ToolFailure.FAILED_DURING_EXECUTION, "Process was killed forcefully after timeout.", null);
                }
                if (ev != 0 && completed) {
                    throw new ToolException(ToolFailure.FAILED_DURING_EXECUTION, String.format("Non-zero exit code (%d)", ev), null);
                }
            }
        } catch (ToolException e) {
            throw e;
        } catch (InterruptedException e) {
            throw new ToolException(ToolFailure.CALL_FAILED,e);
        } catch (IOException e) {            
            throw new ToolException(ToolFailure.MALFORMED_OR_MISSING_INPUT,e);
        }
    }
    protected BufferedReader getBufferedInputReader(Process p) throws UnsupportedEncodingException {
        InputStream is = p.getInputStream();        
        // Frama-c returns result in UTF-8 encoding
        InputStreamReader isr = new InputStreamReader(is, "UTF-8");        
        return new BufferedReader(isr);
    }
    
    protected BufferedReader getBufferedErrorReader(Process p) throws UnsupportedEncodingException {
        InputStream is = p.getErrorStream();        
        // Frama-c returns result in UTF-8 encoding
        InputStreamReader isr = new InputStreamReader(is, "UTF-8");        
        return new BufferedReader(isr);
    }
    public boolean isProcessAlive(Process p){
        try{
            p.exitValue();
            return false;
        }catch(IllegalThreadStateException e){
            return true;
        }
    }
}

