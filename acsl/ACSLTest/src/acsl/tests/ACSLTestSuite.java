package acsl.tests;

import java.io.File;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import org.junit.runner.Description;
import org.junit.runner.Runner;
import org.junit.runner.notification.RunNotifier;
import org.junit.runners.BlockJUnit4ClassRunner;
import org.junit.runners.Suite;
import org.junit.runners.model.FrameworkMethod;

public class ACSLTestSuite extends Suite {
    public static String temp_dir = "Tests_Temp";
    public final File baseDirectory = TestUtility.getTestFilesBase();
    public final ArrayList<Runner> runners = new ArrayList<>();
    protected boolean topDirectory = true; // Tracking state of addFiles through recursion
    
    public ACSLTestSuite(Class<?> clazz) throws Throwable {
        super(clazz, Collections.<Runner>emptyList());
        // create a temp directory in which all the files will be dumped.
        // If directory already existing delete it.
        boolean flag = TestUtility.delete(new File(System.getProperty("user.dir"),temp_dir));
        if (!flag) System.out.println("Failed to delete temp directory " + temp_dir);
        new File(new File(System.getProperty("user.dir")),temp_dir).mkdir();
        TestBase.testcount = 0;
        TestBase.testsuccess = 0;
        TestBase.testfail = 0;
        TestBase.testskip = 0;
        addFiles(baseDirectory);
    }
    
    protected void addFiles(File dir) throws Throwable {
        boolean root = topDirectory;
        topDirectory = false;
        if (dir.isDirectory()) {
            for (File f : dir.listFiles()) {
                addFiles(f);
            }
        } else {
            if (dir.getName().endsWith(".c")) {
                runners.add(new ACSLTestRunner(dir));
            }
        }
        if(root){
            topDirectory = true;
            runners.add(new StatsRunner());
        }
    }
    
    @Override
    protected List<Runner> getChildren() {
        return runners;
    }
    
    protected class ACSLTestRunner extends BlockJUnit4ClassRunner {
        File toRun;
        
        public ACSLTestRunner(File file) throws Throwable {
            super(ACSLTest.class);
            this.toRun = file;
        }
        
        @Override
        protected Object createTest() throws Exception {
            return new ACSLTest().setFile(toRun);
        }
        
        @Override
        protected String getName() {
            String aname = toRun.getAbsolutePath();
            String key = "tests";
            int k = aname.lastIndexOf(key);
            aname = aname.substring(k + key.length() + 1).replace('\\', '/');
            return "["+aname+"]";
        }
        
        @Override
        protected String testName(FrameworkMethod method) {
            return method.getName() + getName();
        }
    }
    
    protected class StatsRunner extends Runner {

        @Override
        public Description getDescription() {
            return org.junit.runner.Description.createTestDescription(StatsRunner.class, "Statistics");
        }

        @Override
        public void run(RunNotifier arg0) {
            TestBase.reportStatistics();
        }
    }
    
   
}
