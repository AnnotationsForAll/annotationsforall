# ACSL Annotations

ACSL is the language used by the code verification tool [Frama-C](http://frama-c.com/). It annotates the C programming language.

# Installation

To use this code, you have to have Frama-C and at least one external prover installed.

## Installing Frama-C

Frama-C uses OCaml to build. Ensure you have OCaml version 3.12.1 or higher before installing Frama-C. You can download OCaml [here](https://ocaml.org/docs/install.html).

Download the most recent version of Frama-C from [here](http://frama-c.com/download.html). Unzip the archive's contents, and with a command window in the unzipped directoy, execute:

```
./configure
make
sudo make install
```

If you are using Cygwin, add the flag `--prefix=C:/cygwin/usr/local/` to the invocation of `./configure`, and omit the `sudo`.

## Installing Alt-Ergo

Alt-Ergo is the prover that Frama-C uses by default. See below for alternate provers you can use instead of Alt-Ergo.

To install Alt-Ergo, download the most recent Alt-Ergo executable from [here](https://alt-ergo.ocamlpro.com/index.php#releases). Place the executable in your /usr/local/bin directory.

## Installing Why3

Frama-C also supports using Why3, a framwork for translating prover languages. Why3 can allow you to use a variety of other provers with Frama-C, including Alt-Ergo.

To install Why3, get the lastest source [here](http://why3.lri.fr/#download). Unzip the archive, and run the follwoing commands inside the resultant directory:

```
./configure
make
sudo make install
```

## Installing Other Provers

Why3 allows you to use provers other than Alt-Ergo with Frama-C. Why3 supports:

* [Alt-Ergo](http://alt-ergo.ocamlpro.com/)
* [Beagle](https://bitbucket.org/peba123/beagle)
* [CVC3](http://www.cs.nyu.edu/acsys/cvc3/)
* [CVC4](http://cvc4.cs.nyu.edu/web/)
* [E-prover](http://www4.informatik.tu-muenchen.de/~schulz/E/E.html)
* [Gappa](http://gappa.gforge.inria.fr/)
* [Metis](http://www.gilith.com/software/metis/)
* [Metitarski](http://www.cl.cam.ac.uk/~lp15/papers/Arith/)
* [Princess](http://www.philipp.ruemmer.org/princess.shtml)
* [Psyche](http://www.lix.polytechnique.fr/~lengrand/Psyche/)
* [Simplify](http://kindsoftware.com/products/opensource/Simplify/)
* [SPASS](http://www.spass-prover.org/)
* [Vampire](http://www.vprover.org/)
* [veriT](http://www.verit-solver.org/)
* [Yices](http://yices.csl.sri.com/)
* [Z3](https://github.com/Z3Prover/z3)

Once other provers are installed, you need to configure it to detect which provers you have on the system. To do so, run the following command:

```
why3 config --detect-provers
```

Why3 should automatically set up your provers for you. If you are on Cygwin, you may have to edit the `.why3.conf` file it generates by prepending instances of `%f` or `%l` with `C:/cygwin`.

Once you have other provers, you can enable them by passing the flag `-wp-prover` to Frama-C. For example, here is how you would use the Z3 prover to verify the annotations in `file.c`:

```
frama-c file.c -wp -wp-prover why3:z3
```

# Using ACSL Annotations

`libraries` contains the annotations for several common C libraries. To enable them while using Frama-C, provide it the following arguments:

```
frama-c ... -no-frama-c-stdlib -cpp-extra-args="<library-includes> -D__FC_MACHDEP_X86_64"
```

Where `<library-includes>` are like so, one for each include:

```
-I<path-to-this-repository>/acsl/libraries/<library-name>/include
```

Where `<path-to-this-repository>` is the path to this repository, and `<library-name>` is the library you need.

For example, if you wanted to use our annotations for libc to prove `file.c` using WP, and this repository was in your home directory, you would do this:

```
frama-c file.c -wp -no-frama-c-stdlib -cpp-extra-args="-I~/annotationsforall/acsl/libraries/libc/include -D__FC_MACHDEP_X86_64"
```

# Testing ACSL Annotations
All the ACSL tests can be executed using ACSLTest Project. It is an Eclipse project and contains JUnit tests. JUnit tests can be executed within Eclipse or by using Ant Script (ACSLTest/runJunitTests.xml)

Some of the tests are configured to use Z3 as the prover. Z3 can be downloaded from [here](https://github.com/Z3Prover/z3/releases) and must be placed in the PATH so that testing system can find it. One can also place them under ACSLTest/tpbin directory as this directory is included in PATH while starting a Frama-c process.

## Import ACSLTest project in Eclipse.
To run the JUnit tests in Eclipse, you will have to import the project in Eclipse. 

1.  Create a new directory (wherever you want) [called $WORKSPACE below] 
2.  Launch Eclipse 
3.  Choose the directory created above [$WORKSPACE] in the dialog asking for the workspace to use 
4.  Choose File -> Import from the main menu 
5.  Double-click General -> Existing Projects into Workspace
6.  Enter $location of ACSLTest project as the root directory
7.  Click 'Finish' (do NOT enable 'Copy projects into workspace') 

## Running JUnit Tests in Eclipse
ACSLTest project has a launcher to execute ACSLTest in Eclipse.

1. In Eclipse, select "Run" menu and click "Run Configurations..." option.
2. Expand JUnit option and select "ACSLTest" launcher.
3. Few environment variables should be set to execute these test. Go to the "Environment" tab.
4. Check that all the environment variables are correct for your system. 
5. If "FRAMA_C_PATH" environment variable is not set, on Windows machine, we assume that it is "C:/cygwin/usr/local/bin/frama-c" and "/usr/local/bin/frama-c" on Linux machine.
6. If "BASH_PATH" environment variable is not set, on Windows machine, we assume that it is "C:/cygwin/bin/bash" and "/usr/local/bin/bash" on Linux machine.
7. After setting the environment variables, Click "Apply" to save the changes and Click "Run" to run the tests.

## Running JUnit Tests in Eclipse via Ant Script
1. Double click on the runJunitTest.xml file in the Eclipse
2. Note that Ant script has two types of tests i.e. "ACSLTest-Sodium-report" and "ACSLTest-GTlibc-report"
3. Navigate to any of these tests and check that "env key" are set correctly.
4. Right click on the Ant file and select "Run As" option. 
5. Select "Ant Build..." option and select the test that you want to run. Make sure "build" is also selected before selecting the test.
6. Click on "Run" to start the tests.

## Running JUnit Test outside Eclipse via Ant Script
1. You can download Ant from https://ant.apache.org/bindownload.cgi. Make sure to download Ant that requires Java8.
2. Set JAVA_HOME environment variable. 
3. Go to the ACSLTest directory and execute ./run_ant.sh, this will start the "ACSLTest-GTlibc-report" tests.

# ACSL Demos

The directory `demos` contains several examples of Frama-C in action, in conjunction with our annotated libraries. See the README in the `demos` directory for information on how to set up and run demos.

Demos have two parts- the "bugged" and "fixed" parts. This represents the results of Frama-C's execution on the codebase before and after a bug fix was made. Notice how Frama-C does not prove all goals for the "before" case, but does for the "after" case.

Look inside each demo directory for more information about that specific demo.
