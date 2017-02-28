package framac.helpers;

import java.io.File;
import java.io.IOException;
import java.util.List;
import java.util.Map;
import java.util.Properties;

import acsl.tests.TestBase;
import acsl.tests.TestOptions;

public class Utils {
    public static String mapSystemFilenameToPosixFilename(String systemFilename) {
        if (systemFilename == null) return null;
        return systemFilename.replace("\\", "/");
    }
    
    public static Process startFramaCProcess(List<String> cmdArgs, String workingDir, TestOptions options) throws IOException{
        ProcessBuilder pb = new ProcessBuilder(cmdArgs);
        if (workingDir != null) pb.directory(new File(workingDir));
        Map<String, String> env = pb.environment();
        String pathVariableName = "Path";
        String path = env.get(pathVariableName);
        if (path == null) {
            pathVariableName = "PATH";
            path = env.get(pathVariableName);
        }
        String addCygwinToPath = "";
        String tpbinPaths = "";
        String whyPath = "";
        String pathSeparator = System.getProperty("path.separator");
        
        {
            String parent = new File(options.why3_path).getParent();
            if (parent != null) {
                whyPath = Utils.mapSystemFilenameToPosixFilename(parent) + pathSeparator;
            }
        }
        if (Utils.getSystemType().equals("WINDOWS")) {
            //In windows, add Cygwin bin to Path
            addCygwinToPath = options.bash_path + File.separator+".." + pathSeparator;
            tpbinPaths = TestBase.THIRD_PARTY_BIN + pathSeparator + 
                        (new File(TestBase.THIRD_PARTY_BIN, "windows")).getAbsolutePath() + pathSeparator;
        } else {
            tpbinPaths = TestBase.THIRD_PARTY_BIN + pathSeparator + 
                    (new File(TestBase.THIRD_PARTY_BIN, "linux")).getAbsolutePath() + pathSeparator;
        }
        String paths = addCygwinToPath + whyPath + tpbinPaths + path;
        env.put(pathVariableName, paths);
        pb.redirectErrorStream(true);
        // Start the process...
        return pb.start();
    }
    
    public static String getSystemType() {
        Properties p = System.getProperties();
        String os = p.getProperty("os.name");
        if (os.startsWith("Windows")) {
            return "WINDOWS";
        }
        return "POSIX";
    }
}
