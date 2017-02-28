package acsl.tests;

import java.io.File;
import java.io.IOException;

import framac.helpers.Utils;

/*@
 * A set of options that can be passed to the test runner to affect the runtime of an individual test.
 * This is created in ACSLTest, and is passed into TestUtility down to FramacWpTests.
 */
public class TestOptions {
    private File file; // The file of the test to run
    public boolean x86_64 = true; // False for 32 bit mode
    public String[] extraArguments = new String[0]; // Any raw arguments to pass to Frama-C
    public String outputDir = new File("temp").getAbsolutePath();
    public String framac_path;
    public String why3_path;
    public String bash_path;
    public TestOptions() {
        setBashPath(null);
        setFramacPath(null);
        setWhy3Path(null);
    }
    
   public void setFramacPath(String path){
       framac_path = (path != null && !path.isEmpty()) ? path : 
                   (Utils.getSystemType().equals("WINDOWS") ? "C:/cygwin/usr/local/bin/frama-c":
                                                              "/usr/local/bin/frama-c");
   }
   
   public void setWhy3Path(String path){
       why3_path = (path != null && !path.isEmpty()) ? path : 
                   (Utils.getSystemType().equals("WINDOWS") ? "C:/cygwin/usr/local/bin/why3":
                                                              "/usr/local/bin/why3");
   }
   
   public void setBashPath(String path){
       bash_path = (path != null && !path.isEmpty()) ? path : 
                   (Utils.getSystemType().equals("WINDOWS") ? "C:/cygwin/bin/bash":
                                                              "/usr/local/bin/bash");
   }
   
   public String getFile() throws IOException{
       return this.file.getCanonicalPath().replace("\\", "/");
   }
   
   public void setFile(File f){
       this.file = f;
   }
}
