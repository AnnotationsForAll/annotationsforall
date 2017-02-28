package acsl.tests.helpers;

import java.util.List;

import framac.helpers.CommandLineProblemListener;
import acsl.tests.TestOptions;
//import speedy.config.NamedSpeedyArgument;
//import speedy.config.SpeedyOptions;
//import speedy.shared.core.IProblemListener;

public class FramacWpWithWhyTests extends FramacWpTests{
    
    public FramacWpWithWhyTests(TestOptions testOptions, List<String> args, CommandLineProblemListener problemListener) {
        super(testOptions, args, problemListener);
    }

    @Override
    protected List<String> buildSpecificCommandArgs()  {
        
        List<String> args =  super.buildSpecificCommandArgs();
        
        /*if(!options.getString(NamedSpeedyArgument.FRAMACWPWHYPROVER).isEmpty()){
            args.add("-wp-prover");
            args.add("why3:" + options.getString(NamedSpeedyArgument.FRAMACWPWHYPROVER));
        }*/
        return args;        
    }
}
