package framac.helpers;


/** Implements a problem listener, invoked when various errors or warnings are encountered */
public class CommandLineProblemListener  {

    public void report(String kind, String msg, Object filename, int lineNumber, int start, int end, Object result) {
        // FIXME - log the kind of problem? Will change lots of test results.
        if (start == -1) {
            // FIXME - remove the -1:-1 - but then have to change the tests
            if(filename != null){
                System.out.println(filename.toString().replace("\\", "/")
                            + ":" + lineNumber + ":"+ start + "-" + end + ":" + msg);
            }else{
                System.out.println(filename + ":" + lineNumber + ":"+ start + "-" + end + ":" + msg);
            }
        } else {
            if(filename != null){
                System.out.println(filename.toString().replace("\\", "/")
                        + ":" + lineNumber + ":"+ start + "-" + end + ":" + msg);
            }else{
                System.out.println(filename + ":" + lineNumber + ":"+ start + "-" + end + ":" + msg);
            }
        }
    }

}