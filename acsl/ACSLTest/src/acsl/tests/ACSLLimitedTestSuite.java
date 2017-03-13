package acsl.tests;

import java.io.File;
import java.util.ArrayList;
import java.util.List;


public class ACSLLimitedTestSuite extends ACSLTestSuite {
    
    private List<File> allowList, checkList;
    
    public ACSLLimitedTestSuite(Class<?> clazz) throws Throwable {
        super(clazz);
    }
    
    @Override
    protected void addFiles(File dir) throws Throwable {
        if(topDirectory) {
            allowList = getAllowList(TestUtility.getSpecFilesBase(), null);
            checkList = new ArrayList<File>(allowList);
        }
        boolean root = topDirectory;
        topDirectory = false;
        if (dir.isDirectory()) {
            for (File f : dir.listFiles()) {
                if (!f.getName().equals(".svn")) {
                    addFiles(f);
                }
            }
        } else {
            if (dir.getName().indexOf("test_") == 0) {
                File checkDir;
                if ((checkDir = checkAllowList(allowList, dir.getName().substring(5))) != null) {
                    if(!checkList.remove(checkDir)) {
                        System.err.println("Multiple tests found for "+dir.getName());
                    }
                    runners.add(new ACSLLimitedTestRunner(dir, checkDir));
                } // else: No target for test
            } else {
                System.err.println("Non-standard test name detected: "+dir.getName());
            }
        }
        if(root){
            if (!checkList.isEmpty()) {
                System.err.println("Tests were NOT found for the following:");
                for (File f: checkList) {
                    System.err.println("  "+f.getName());
                }
            }
            topDirectory = true;
            runners.add(new StatsRunner());
        }
    }
    
    private File checkAllowList(List<File> allowList, String name) {
        for (File f: allowList) {
            if (    f.isFile() && 
                    f.getName().equals(name) ) {
                return f;
            }
        }
        return null;
    }

    private List<File> getAllowList(File dir, List<File> allowList) {
        if(allowList == null) {
            allowList = new ArrayList<File>();
        }

        if (dir.isDirectory()) {
            for (File f : dir.listFiles()) {
                getAllowList(f, allowList);
            }
        } else {
            if(dir.getName().endsWith(".c")) {
                allowList.add(dir);
            }
        }
        
        return allowList;
    }
    
    
    protected class ACSLLimitedTestRunner extends ACSLTestRunner {
        protected File include; 
        
        public ACSLLimitedTestRunner(File file, File include) throws Throwable {
            super(file);
            this.include = include;
        }

        @Override
        protected Object createTest() throws Exception {
            return ((ACSLLimitedTest)new ACSLLimitedTest().setFile(toRun)).setInclude(include);
        }
        
    }
}
