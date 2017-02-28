package acsl.tests.helpers;

import java.util.List;

import org.junit.Assert;

import framac.helpers.SpecificationChecker.CheckerResult;
import acsl.tests.TestOptions;
import framac.helpers.CommandLineGoalResultListener;
import framac.helpers.CommandLineProblemListener;
import framac.helpers.ToolException;
//import speedy.Speedy;
//import speedy.config.NamedSpeedyArgument;
//import speedy.config.SpeedyOptions;
//import speedy.config.SpeedyOptions.InvalidArgumentsException;
//import speedy.core.CommandLineGoalResultListener;
//import speedy.core.ISubResultListener;
//import speedy.shared.core.CommandLineProblemListener;
//import speedy.shared.core.IProblemListener;
//import speedy.tools.interfaces.SpecificationChecker.TaskDefinition;
//import speedy.tools.interfaces.ToolException;

/**
 * Sets up the environment to run a FramacWpTests
 */
public class FramacWpTestRunner {

    public static final String BASH_PATH = "BASH_PATH";
    public static final String FRAMA_C_PATH = "FRAMA_C_PATH";
    
    //public SpeedyOptions options;
    public CommandLineProblemListener problemListener;
    public CommandLineGoalResultListener subCheckResultListener;
    public TestOptions testOptions;
    public List<String> args;
    
    public FramacWpTestRunner(List<String> args, TestOptions testOptions) 
            //throws InvalidArgumentsException 
    {
        //options = SpeedyOptions.optionsFromArguments(args);
        //options.putValue(NamedSpeedyArgument.BASHCMD, System.getenv(BASH_PATH));
        //options.putValue(NamedSpeedyArgument.FRAMAEXE, System.getenv(FRAMA_C_PATH));
        this.args = args;
        testOptions.setFramacPath(System.getenv(FRAMA_C_PATH));
        testOptions.setBashPath(System.getenv(BASH_PATH));
        problemListener = new CommandLineProblemListener();
        //subCheckResultListener = new CommandLineGoalResultListener();
        //Speedy.options = options;
        this.testOptions = testOptions;
    }
    
    public int run() {
        //List<String> fcns = options.<String>getList(NamedSpeedyArgument.FUNCTIONS);
        //TaskDefinition taskDef = new TaskDefinition(options.listOfFiles, fcns == null ? null : fcns.get(0));
        CheckerResult cr = null;
        try {
            cr = new FramacWpTests(testOptions, args, problemListener).runTool();
        } catch (ToolException e) {
            e.printStackTrace();
            Assert.assertTrue("Exception", false);
        }
        return cr == CheckerResult.ALL_PROPERTIES_SATISFIED ? 0 : 1;
    }
    
    public int runWithWhy() {
        //List<String> fcns = options.<String>getList(NamedSpeedyArgument.FUNCTIONS);
        //TaskDefinition taskDef = new TaskDefinition(options.listOfFiles, fcns == null ? null : fcns.get(0));
        CheckerResult cr = null;
        try {
            cr = new FramacWpWithWhyTests(testOptions, args, problemListener).runTool();
        } catch (ToolException e) {
            e.printStackTrace();
            Assert.assertTrue("Exception", false);
        }
        return cr == CheckerResult.ALL_PROPERTIES_SATISFIED ? 0 : 1;
    }
}


