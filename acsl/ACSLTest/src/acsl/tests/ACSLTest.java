package acsl.tests;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

import org.junit.Ignore;
import org.junit.Test;
import org.junit.runner.RunWith;

@RunWith(ACSLTestSuite.class)
public class ACSLTest extends TestBase {
    private static final String OPTIONS_COMMENT = "//OPTIONS:";
    
    TestOptions options = new TestOptions();
    
    public ACSLTest() {
        
    }
    
    public ACSLTest setFile(File file) {
        options.setFile(file);
        try {
            BufferedReader br = new BufferedReader(new FileReader(file));
            
            for (String line = br.readLine(); line != null; line = br.readLine()) {
                if (line.contains(OPTIONS_COMMENT)) {
                    String[] beforeAfter = line.split(OPTIONS_COMMENT);
                    String after = beforeAfter[beforeAfter.length-1];
                    String[] optionPairs = after.split("\\s+");
                    // TODO: This currently does not correctly group together "arguments in quotes like this".
                    // To do so, we will need to change this split regex into a matching one, with this pattern:
                    // \w+|"[\w\s]*"
                    options.extraArguments = optionPairs;
                    break;
                }
            }
            
            br.close();
        } catch (IOException e) {
            System.err.printf("An IO error occured when parsing test file %s for options: %s\n", file, e);
        }
        return this;
    }

    @Ignore
    @Test
    public void test_with_alt_ergo() throws Exception {
        TestUtility.acslTestCaseWithWhy(options, "alt-ergo");
    }
    
    @Ignore
    @Test
    public void test_with_z3() throws Exception {
        TestUtility.acslTestCaseWithWhy(options, "z3-4.4.0");
    }
    
    @Test
    public void test() throws Exception {
        TestUtility.acslTestCase(options);
    }
}
