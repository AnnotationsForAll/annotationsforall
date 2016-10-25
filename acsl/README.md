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
frama-c ... -no-frama-c-stdlib -cpp-extra-args="''library-includes'' -D__FC_MACHDEP_X86_64"
```

Where ''library-includes'' are like so, one for each include:

```
-I''path-to-this-repository''/acsl/libraries/''library-name''/include
```

For example, if you wanted to use our annotations for libc to prove `file.c` using WP, and this repository was in your home directory, you would do this:

```
frama-c file.c -wp -no-frama-c-stdlib -cpp-extra-args="-I~/acsl/libraries/libc/include -D__FC_MACHDEP_X86_64"
```

# Testing ACSL Annotations

There is a test script common for all ACSL tests, called `test.py`. The first argument is the library folder. Any other positional arguments represent a filter, so you can run only certain test files. For example, to run the tests for libc, run:

```
python test.py libraries/libc
```

This will run the tests and display the results. If a file's test failed, it will display a list of goals in the file that have failed.

There are three kinds of tests: runSuccess, runFailure, and testValues. runSuccess tests fail if any goal in them fails. runFailure tests fail if all goals in them pass. testValues tests fail if any goal fails, except for the vacuous test (an attempt to prove "false"), which must fail for testValues to pass.

`test.py` also takes several flags. These are:

| Short Name | Long Name | Description |
|---|---|---|
| -h | --help | Prints this help information. |
| -a | --fc-args | The next argument will be passed to Frama-C as arguments. |
| -e | --fc-exe | Specify the path to the Frama-C executable this script will execute. |

# ACSL Demos

The directory `demos` contains several examples of Frama-C in action, in conjunction with our annotated libraries. See the README in the `demos` directory for information on how to set up and run demos.

Demos have two parts- the "bugged" and "fixed" parts. This represents the results of Frama-C's execution on the codebase before and after a bug fix was made. Notice how Frama-C does not prove all goals for the "before" case, but does for the "after" case.

Look inside each demo directory for more information about that specific demo.