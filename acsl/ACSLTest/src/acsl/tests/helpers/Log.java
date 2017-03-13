// GT_EXTERNAL_LEGEND(2014) 
// Reviewed: DRCok 2016-03-09

package acsl.tests.helpers;

import java.io.PrintWriter;
import java.io.StringWriter;

import org.eclipse.jdt.annotation.NonNull;
import org.eclipse.jdt.annotation.Nullable;

import framac.helpers.Utils;


/** The logging mechanism for the plugin - used for reporting progress or
 * errors within the plugin itself.  All textual user output is sent to
 * the static methods of this class; specific kinds of reporters register as listeners.
 * Actually - in the current implementation there can be only one listener.
 * @author David R. Cok
 */
public class Log {

    /** The singleton Log object that does the actual logging */
    /*@ non_null */
    public static Log log = new Log();

    /** Call this method for any non-error output - it sends the message on to the 
     * current listener, or to System.out if there are no listeners
     * @param message the message to write; a line terminator will be added
     */
    static public void log(@NonNull String message) { 
        if (log.listener != null) log.listener.log(message);
        System.out.println(message); 
    }
    
    static public void log(String filename, int linenumber, int start, int end, @NonNull String message) { 
        String mssg = Utils.mapSystemFilenameToPosixFilename(filename)
                + ":" + linenumber + ":"+ start + "-" + end + ":" + message;
        log(mssg);
    }

    /** Call this method for any error output that happens because of an
     * exception - it sends the message to the 
     * current listener, or to System.out if there are no listeners;
     * if the second argument is non-null, the stack trace is included
     * @param message the message to write; a line termination will be added
     */
    static public void errorLog(@NonNull String message, @Nullable Throwable e) {
        String emsg = e == null ? null : e.getMessage();
        if (emsg != null && emsg.length() != 0) message = message + " (" + emsg + ")"; //$NON-NLS-1$ //$NON-NLS-2$
        if (e != null) {
            StringWriter sw = new StringWriter();
            PrintWriter pw = new PrintWriter(sw);
            pw.println();
            e.printStackTrace(pw);
            message = message + sw.toString(); 
        }
        log(message); 
    }
    
    static public void errorLog(String filename, int linenumber, int start, int end,@NonNull String message, @Nullable Throwable e) {
        String mssg = Utils.mapSystemFilenameToPosixFilename(filename)
                + ":" + linenumber + ":"+ start + "-" + end + ":" + message;
        errorLog(mssg,e);
    }

    /** The interface expected of listeners */ 
    public static interface IListener {
        /** Records the argument, with an appended newline, as appropriate for the receiving listener */
        public void log(@NonNull String msg);
    }
    
    /** An implementation of the IListener interface that includes a
     * delegate listener.
     */
    public static abstract class DelegateListener implements IListener {
        protected @Nullable IListener delegate = null;
        public @Nullable IListener delegate() { return delegate; }
    }
    
    /** The one (if any) registered listener */
    /*@ nullable */
    protected @Nullable IListener listener = null;

    /** Returns the current listener */
    public @Nullable IListener listener() {
        return listener;
    }

    /** Call this to set or remove the current listener */
    public @Nullable IListener setListener(@Nullable IListener l) {
        IListener old = listener;
        listener = l;
        return old;
    }

}
