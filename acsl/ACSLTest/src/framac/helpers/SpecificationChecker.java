package framac.helpers;

/** An interface holding classes that abstractly represent checking tools */
public interface SpecificationChecker extends AutoCloseable {

    /** An object representing the result of a checking operation */
    public enum CheckerResult {
        UNKNOWN_RESULT,
        NO_PROPERTIES_PRESENT,
        ALL_PROPERTIES_SATISFIED,
        ALL_PROPERTIES_VIOLATED,
        SOME_PROPERTIES_VIOLATED,
        EXECUTION_FAILED;
        
        public String reason;
        
        public CheckerResult aggregateWith(CheckerResult addResult) {
            switch (this) {
            case EXECUTION_FAILED:
                return this;

            case NO_PROPERTIES_PRESENT:
                return addResult;

            case ALL_PROPERTIES_SATISFIED:
                switch (addResult) {
                case NO_PROPERTIES_PRESENT:
                case ALL_PROPERTIES_SATISFIED:
                    return this;
                case SOME_PROPERTIES_VIOLATED:
                case ALL_PROPERTIES_VIOLATED:
                case EXECUTION_FAILED:
                    return addResult;
                default:
                    return UNKNOWN_RESULT;
                }

            case SOME_PROPERTIES_VIOLATED:
                switch (addResult) {
                case NO_PROPERTIES_PRESENT:
                case ALL_PROPERTIES_SATISFIED:
                case SOME_PROPERTIES_VIOLATED:
                    return this;
                case ALL_PROPERTIES_VIOLATED:
                case EXECUTION_FAILED:
                    return addResult;
                default:
                    return UNKNOWN_RESULT;
                }
            case ALL_PROPERTIES_VIOLATED:
                return ALL_PROPERTIES_VIOLATED;
            default:
                return UNKNOWN_RESULT;
            }
        }
    }

}
