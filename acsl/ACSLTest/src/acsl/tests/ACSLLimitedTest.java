package acsl.tests;

import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;

import acsl.tests.helpers.FramacWpTestRunner;
//import speedy.config.SpeedyOptions.InvalidArgumentsException;

@RunWith(ACSLLimitedTestSuite.class)
public class ACSLLimitedTest extends ACSLTest {
    File include;
    
    public ACSLLimitedTest() {
        super();
    }
    
    public ACSLLimitedTest setInclude(File file) {
        this.include = file;
        return this;
    }
    
    @Test
    public void test_with_alt_ergo() throws Exception {
        acslTestCaseWithWhy("alt-ergo");
    }

    @Test
    public void test_with_z3() throws Exception {
        acslTestCaseWithWhy("z3-4.4.0");
    }
    
    protected void acslTestCaseWithWhy(String prover) {
        int res = 0;
        try {
            String path = options.getFile();
            List<String>fcwpca = new ArrayList<String>();
            fcwpca.add("-cpp-extra-args");
            fcwpca.add("-include "+include.getAbsolutePath());
            fcwpca.add("-cpp-extra-args");
            fcwpca.add("-I"+include.getParentFile().getAbsolutePath());
            /*String fcwpca = "\"-cpp-extra-args='-include "+include.getAbsolutePath() + "' " +
                    "-cpp-extra-args=-I"+include.getParentFile().getAbsolutePath();*/
            for(String s: TestUtility.getImportPaths()) {
                //fcwpca += " -cpp-extra-args=-I"+(new File(s)).getAbsolutePath();
                fcwpca.add("-cpp-extra-args");
                fcwpca.add("-I"+(new File(s)).getAbsolutePath());
            }
            //fcwpca += " -wp-model=Typed+cast";
            //fcwpca += "\""; 
            fcwpca.add("-wp-model");
            fcwpca.add("Typed+cast");
            String args[] = {path, "-wp-prover","why3:"+prover};
            List<String> fc_args = Arrays.asList(args);
            fc_args.addAll(fcwpca);
            FramacWpTestRunner fcwpr = new FramacWpTestRunner(fc_args, options);
            res = fcwpr.runWithWhy();
        } catch (Exception e) {
            Assert.fail("Exception");
        }
        Assert.assertEquals("Unexpected exit value", 1, res);
    }
    
}
