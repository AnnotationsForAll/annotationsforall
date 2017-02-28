#!/bin/bash
## GT_EXTERNAL_LEGEND(2014) 
## This script is intended only to be used by the testbot in the testbot test environment, on the test machine named 'speedy'.
## As you can see it contains hard-coded paths for the testbot user in a cygwin environment.
## The script compiles speedy from scratch, including building the antlr grammar, then a build of all of the 
## Eclipse projects that make up Speedy, and then launches the junit tests and
## the plugin junit tests, reporting their results to the data manager.

if [ -z "$JAVA_HOME" ]; then 
    echo "JAVA_HOME is not set. JAVA_HOME is required to run ant script."
    exit 1
fi
export PATH=../../third-party/ant/bin:${PATH}

ant -buildfile runJunitTests.xml cleanall build ACSLTest-GTlibc-report

