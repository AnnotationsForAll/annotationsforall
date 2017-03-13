package acsl.tests;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

import org.junit.Assert;
import org.junit.runner.Description;


//import speedy.config.SpeedyOptions.InvalidArgumentsException;
import acsl.tests.helpers.FramacWpTestRunner;
import acsl.tests.helpers.FramacWpTests;

public class TestUtility {

    // This env variable must point to the directory with the acsl test cases
    public static final String ACSL_TEST_DIR_ENV            = "ACSL_TEST_FILES";
    public static final String REPORT_TO_DATAMANAGER_ENV    = "ANNOTATIONS_REPORT";
    private static HashSet<String> expectedFailures = null;
    
    public static File getTestFilesBase() {
        String testDir = System.getenv(ACSL_TEST_DIR_ENV);
        if(testDir == null){
            Assert.fail("Test mis-configured: requires env variable '"+ACSL_TEST_DIR_ENV+"'");
        }
        return new File(testDir);
    }
    
    public static File getExpectedFailuresFile() {
        return new File(getTestFilesBase(), "expected_failures.txt");
    }
    
    public static List<String> getImportPaths() {
        List<String> results = new ArrayList<String>();
        String importPath = System.getenv(FramacWpTests.IMPORT_PATH);
        if (importPath != null) {
            String[] paths = importPath.split(";");
            for (String path : paths) {
                results.add(path);
            }
        }
        
        return results;
    }
    
    public static File getSpecFilesBase() {
        List<String> specs = getImportPaths();
        if(specs.isEmpty()){
            Assert.fail("Test mis-configured: requires env variable '"+FramacWpTests.IMPORT_PATH+"'");
        }
        return new File(specs.get(0));
    }
    
    /**
     * ACSL test case file must have the following functions to test preconditions:
     * runSuccess, runFailure
     * These can either be annotated with preconditions, or make calls to the function being tested.
     * 
     * ACSL test case file must have the following function to test behavior:
     * testValues
     * this function can also contain an assertion 'vacuous' which tests for a contradiction.
     */
    public static void acslTestCase(TestOptions options) {
        int res = 0;
        try {
            String path = options.getFile();
            String args[] =  {path};
            FramacWpTestRunner fcwpr = new FramacWpTestRunner(Arrays.asList(args), options);
            res = fcwpr.run();
        } catch (Exception e) {
            Assert.fail("Exception");
        }
        Assert.assertEquals("Unexpected exit value", 1, res);
    }
    
    public static void acslTestCaseWithWhy(TestOptions options, String prover) {
        int res = 0;
        try {
            String path = options.getFile();
            String args[] = { path, "-wp-prover","why3:"+prover};
            FramacWpTestRunner fcwpr = new FramacWpTestRunner(Arrays.asList(args), options);
            res = fcwpr.runWithWhy();
        } catch (Exception e) {
            Assert.fail("Exception");
        }
        Assert.assertEquals("Unexpected exit value", 1, res);
    }
    
    /**
     * Returns if reports should be sent to the datamanger (configured by env)
     */
    public static boolean reportToDataManager() {
        return (System.getenv(REPORT_TO_DATAMANAGER_ENV) != null);
        
    }

    public static boolean isExpectedFail(Description description) {
        if(expectedFailures == null) {
            // Load expected failures list
            expectedFailures = new HashSet<String>();
            File f = getExpectedFailuresFile();
            if(f.exists()) {
                FileInputStream fis;
                try {
                    fis = new FileInputStream(f);
                    BufferedReader br = new BufferedReader(new InputStreamReader(fis));
                    String line = null;
                    while((line = br.readLine()) != null) {
                        if(!line.isEmpty() && line.charAt(0) != '#'){
                            if(!line.contains("[")) {
                                expectedFailures.add("test_with_alt_ergo["+line+"]");
                                expectedFailures.add("test_with_z3["+line+"]");
                            }else{
                                expectedFailures.add(line);
                            }
                        }
                    }
                    br.close();
                } catch (IOException e) {
                    assert(false);
                    e.printStackTrace();
                }
            }
        }
        String ident = description.getMethodName();
        return expectedFailures.contains(ident);
    }
    
    /** Recursively deletes a file or directory and its contents; returns false if
     * something went wrong in the process (which may leave the job partially complete). */
    public static boolean delete(File file) {

        if (file == null) return true;

        if (!file.isDirectory()) return file.delete();

        File[] flist = file.listFiles();
        if (flist != null) {
            boolean r = true;
            for (File f : flist) {
                if (!delete(f)) r = false;
            }
            if (!r) return r;
        }

        return file.delete();
    }
    
}
