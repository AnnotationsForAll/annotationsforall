# Description

This is a proof that a bug existed in the codebase of The Silver Searcher, a filesystem searching tool written in C.
The issue we are checking for is [fixed in this commit](https://github.com/ggreer/the_silver_searcher/commit/7d3e02f452964294f6835362391a113838dafa59).

# Running

If Frama-C complains about header files missing, you probably don't have libpcre-dev or liblzma-dev installed on your system. Use apt-get to install them on Linux, or apt-cyg if on Cygwin.

All the goals are expected to pass in the fixed version of the code.

# Details

See `src/util.c` in both versions for more details about the proof.
