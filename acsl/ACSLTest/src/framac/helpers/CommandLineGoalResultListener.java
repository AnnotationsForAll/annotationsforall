package framac.helpers;


public class CommandLineGoalResultListener {
    
    public void checkerResultReport(SpecificationChecker checker,
            String resultFor,
            String inFileWithName, String forFunctionName, int onLineNumber,
            Boolean subResult, String description) {
        System.out.println(String.format("%s:%d: (%s) result for %s %s: %s %s", 
                inFileWithName.replace("\\", "/"), 
                onLineNumber,
                checker.getClass().getSimpleName(), 
                resultFor,
                forFunctionName, 
                subResult ? "Satisfied" : "Violated",
                (description != null && !description.isEmpty()) ? description : ""));
    }

    public void createSpecificationSuggestion(SpecificationChecker checker,
            String prefix,
            String inFileWithName, String forFunctionName, int onLineNumber, int offset,
            String suggestionTool,
            String suggestion) {
        System.out.println(String
                .format(prefix + " for function \"%s\" on line %d is:" + '\n' + "%s",
                        forFunctionName,
                        onLineNumber,
                        suggestion));
    }
}
