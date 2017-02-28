package framac.helpers;

public class ToolException extends Exception{
    public enum ToolFailure {
        CALL_FAILED,
        FAILED_DURING_EXECUTION,
        MALFORMED_OR_MISSING_OUTPUT,
        MALFORMED_OR_MISSING_INPUT,
        USER_ERROR;
    }
    public String completeToolLog = null;
    
    private static final long serialVersionUID = 1L;
    
    public ToolException(ToolFailure failureKind, Throwable e) {
        super(failureKind.name() + 
                ((e.getMessage() == null 
                    || e.getMessage().isEmpty()) ? 
                            "" : " - "+e.getMessage()),
                            e);
    }
    
    public ToolException(ToolFailure failureKind, int exitCode) {
        super(String.format("%s with exit value %d", failureKind.name(), exitCode));
    }
    
    public ToolException(ToolFailure failureKind) {
        super(failureKind.name());
    }
    
    public ToolException(ToolFailure failureKind, String details, String completeLog) {
        super(String.format("%s: %s", failureKind.name(), details));
        this.completeToolLog = completeLog;
    }
}
