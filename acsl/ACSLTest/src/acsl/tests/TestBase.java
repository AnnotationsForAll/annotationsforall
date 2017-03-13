package acsl.tests;

import java.io.*;
import java.util.LinkedList;
import java.util.List;
import java.util.Properties;
import java.util.Scanner;

import org.eclipse.jdt.annotation.NonNull;
import org.eclipse.jdt.annotation.Nullable;
import org.junit.After;
import org.junit.Before;
import org.junit.Rule;
import org.junit.internal.AssumptionViolatedException;
import org.junit.rules.TestWatcher;
import org.junit.runner.Description;

import acsl.tests.helpers.Log;

//import speedy.core.Strings;
//import speedy.shared.core.Log;
//import speedy.shared.core.Log.IListener;
//import speedy.shared.core.NullCheck;

/**
 * Ported from SpeedyTest's TestBase
 */
@SuppressWarnings("nls")
public class TestBase {
    // If reporting to datamanager, this env value will be included in the genus name. It can be used to differentiate the libraries.
    //static final public String TEST_GENUS_NAME_ENV = "TEST_GENUS_NAME";
    static final public String THIRD_PARTY_BIN = "tpbin"; 
    
    static public int testcount = 0;
    static public int testsuccess = 0;
    static public int testfail = 0;
    static public int testskip = 0;
    
    /** This class is notified when a test completes, so it can report the test to the GrammaTech data manager */
    @Rule public AnnotationsTestWatcher watcher = new AnnotationsTestWatcher();
    
    public boolean captureLoggedText = true;
    
    // Caution: There are two test names to know about
    // The test Description contains a DisplayName. This is set in ParameterizedWithNames to
    // be a string containing the parameters of the parameterized test. This DisplayName is shown
    // in the JUnit runner (e.g., in Eclipse).
    // The second name is the name set in the watcher by the test itself. It is used just in
    // formulating names of log files, so it needs to be a simple string that can be part of the 
    // file name. Note that the Descxription.getMethodName will return the method name of the 
    // test, which will be the same for many tests if parameters are used.

    public @Nullable String testName() {
        return watcher.testName();
    }
    
    public class AnnotationsTestWatcher extends TestWatcher {
        /** Name used within AnnotationsTestWatcher to construct filenames of expected and actual output */
        protected @Nullable String testName;
        
        /** The file that captures the actual output */
        protected String logFile;
        
        /** A Writer to the log file */
        protected PrintWriter pw;
        
        /** Returns the testName as set by setTestName; this is not the display name provided by ParameterizedWithNames */
        public @Nullable String testName() { return testName; }
        
        /** Sets the test name as used by AnnotationsTestWatcher */
        public void setTestName(@Nullable  String testName) {
            this.testName = testName;
        }

        // This is called before setUp() is called.
        @Override
        protected void starting(Description d) {
            ++testcount;
            Log.log("--------------[" + testcount + "] Starting " + d.getDisplayName());
            if (testName == null) testName = d.getMethodName();
            String testClass = d.getClassName().substring(d.getClassName().lastIndexOf('.')+1);
            
            // FIXME - we are setting a log listener both here and in setUp()? but just removing it in tearDown()?
            // FIXME - this code here is necessary to get the reporting to the datamanager
            if (captureLoggedText) {
                logFile = ACSLTestSuite.temp_dir + "/" + testClass + "." + testName.replaceAll("[/\\\\]", "-") + ".txt"; 
                logFile = logFile.replaceAll("[\"\\[\\]]","-");
                File file = new File(logFile);
                try {
                    pw = new PrintWriter(new FileWriter(file));
                } catch(IOException e) {
                    e.printStackTrace();
                    pw = null;
                }
                usualListener = new Log.IListener() {

                    @Override public void log(@NonNull String msg) {
                        if (pw != null) {
                            pw.println(msg);
                            pw.flush();
                        }
                    }

                };

                
                Log.log.setListener(usualListener);
            }
        }
        
        /** Called by the test runner when a test fails */
        @Override
        protected void failed(Throwable e, Description description) {
            ++testfail;
            if (e instanceof AssertionError) report(TestUtility.isExpectedFail(description)?3:0,description);
            else {
                Log.errorLog("Exception in " + description,e);
                report(1,description);
            }
        }

        /** Called by the test runner when a test succeeds */
        @Override
        protected void succeeded(Description description) {
            ++testsuccess;
            report(5,description);
        }
        
        /** Called by the test runner when a test is skipped */
        @Override
        protected void skipped(AssumptionViolatedException e, Description description) {
            ++testskip;
            report(2,description);
        }
        
        /** Utility method to record results and optionally forward test results to the data manager */
        protected void report(int result, Description description) {
            String testname = description.getMethodName(); // This is not really the method name, but the display name without the class (which is the genus)
            String genus = description.getMethodName(); //genus name is grouped by folder of test
            genus = genus.substring(genus.indexOf('[')+1, genus.length()-1); //strip the test type and the []
            genus = genus.substring(0, genus.lastIndexOf('/')); //strip the file name
            if (pw != null) {
                pw.close();
                pw = null;
            }
            if (TestUtility.reportToDataManager()) {
                reportToDatamanager(testname,genus,result,logFile);
            }
            
            // remove log file
            //TODO: committing for time being to know what is failing.
           /* if (logFile != null) {
                new File(logFile).delete();
            }*/
        }
        
    }
    
    public static class UnitTestLog implements Log.IListener {

        public List<String> messages = new LinkedList<String>();
        public Log.IListener listener;
        
        public UnitTestLog(Log.IListener listener) {
            this.listener = listener;
        }
        
        @Override
        public void log(@NonNull String msg) {
            messages.add(msg);
            if (listener != null) listener.log(msg);
        }
        
    }
    
    Log.IListener usualListener = null;
    protected UnitTestLog newListener = null;

    /** Creates and installs a new Log listener to capture all of the output during the test */
    @Before
    public void setUp() throws Exception {
        if (captureLoggedText) usualListener = Log.log.setListener(newListener = new UnitTestLog(usualListener));
    }
    
    /** Removes the listener installed in setUp() */
    @After
    public void tearDown() throws Exception {
        if (usualListener != null) Log.log.setListener(usualListener);
        newListener = null;
        //killAltErgoProcess();
    }
    
    /** (Partial) command-line for reporting test results to the GrammaTech datamanager;
     * the executable path is relative to trunk/annotations/ACSLTest */
    static final private String[] report = {"","py/test_report.py","","","","",""};
    
    /** Reports a test result to the data manager (if the ANNOTATIONS_REPORT environment
     * variable is set).
     * @param testname name of the test
     * @param testgenus category of test
     * @param result result of the test (5 is good, <5 is varying degrees of bad)
     */
    public void reportToDatamanager(String testname, String testgenus, int result, String logFile) {
        try {
            if(getSystemType().equals("WINDOWS")){
                report[0] = "C://Python27/python";
            }else{
                report[0] = "/usr/bin/python";
            }
            report[2] = testname;
            report[3] = testgenus;
            report[4] = Integer.toString(result);
            report[5] = logFile ;
            final Process p = Runtime.getRuntime().exec(report);
            final StringBuffer buf = new StringBuffer();
            new Thread(new Runnable(){
                public void run(){
                    @SuppressWarnings("resource")
                    Scanner sc = new Scanner(p.getInputStream());
                    while(sc.hasNext()){
                        buf.append(sc.nextLine()).append("\n");
                    }
                }
            }).start();
            new Thread(new Runnable(){
                public void run(){
                    @SuppressWarnings("resource")
                    Scanner sc = new Scanner(p.getErrorStream());
                    while(sc.hasNext()){
                        buf.append(sc.nextLine()).append("\n");
                    }
                }
            }).start();
            int exitValue = p.waitFor(); // TODO - do we need to wait for the submission to complete?
            //Log.log(buf.toString());
            if (exitValue != 0) {
                Log.errorLog("Unexpected exit value when reporting to datamanager: " + exitValue,null);
                Log.log("  Trying to report " + testname + " " + testgenus + " " + result);
            }
            else Log.log("Reported " + testname + " " + testgenus + " " + result + " " + logFile);
        } catch (Exception e) {
            Log.errorLog("Exception occurred when reporting to datamanager",e);
        }
    }
    
    static public void reportStatistics() {
        String message = ("Test counts: total = " + TestBase.testcount 
                + ", success = " + TestBase.testsuccess
                + ", fail = " + TestBase.testfail
//                + ", skip = " + TestBase.testskip
                );
        // Note: statically ignored tests are never started or counted

        if (!TestUtility.reportToDataManager()) {
            Log.log(message);
            return;
        }

        try {
            if(getSystemType().equals("WINDOWS")){
                report[0] = "C://Python27/python";
            }else{
                report[0] = "/usr/bin/python";
            }
            report[2] = "stats";
            report[3] = message;
            report[4] = Integer.toString(testcount);
            report[5] = Integer.toString(testsuccess);
            report[6] = Integer.toString(testfail);
            final Process p = Runtime.getRuntime().exec(report);
            final StringBuffer buf = new StringBuffer();
            new Thread(new Runnable(){
                public void run(){
                    @SuppressWarnings("resource")
                    Scanner sc = new Scanner(p.getInputStream());
                    while(sc.hasNext()){
                        buf.append(sc.nextLine()).append("\n");
                    }
                }
            }).start();
            new Thread(new Runnable(){
                public void run(){
                    @SuppressWarnings("resource")
                    Scanner sc = new Scanner(p.getErrorStream());
                    while(sc.hasNext()){
                        buf.append(sc.nextLine()).append("\n");
                    }
                }
            }).start();
            int exitValue = p.waitFor(); // TODO - do we need to wait for the submission to complete?
            //Log.log(buf.toString());
            if (exitValue != 0) {
                Log.errorLog("Unexpected exit value when reporting statistics to datamanager: " + exitValue,null);
            }
            System.out.println(message);
        } catch (Exception e) {
            Log.errorLog("Exception occurred when reporting statistics to datamanager",e);
            Log.log(message);
        }
    }
    
    public static String getSystemType() {
        Properties p = System.getProperties();
        String os = p.getProperty("os.name");
        if (os.startsWith("Windows")) {
            return "WINDOWS";
        }
        return "POSIX";
    }
    
}
