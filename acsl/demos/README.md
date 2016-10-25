# ACSL Usage Demos

This directory contains several example repositories, showing how one might use ACSL to find bugs in real-world software projects.

# Setting Up The Demo

Each demo is stored as a set of patches to two different versions of a publicily available repository. To run the demo, the repositories have to be downloaded and the patches have to be applied.
Inside each demo is a script called `setup.sh`. Run this script to automatically set up both the bugged and fixed version of the code, patched with ACSL annotations.

# Running The Demo

To verify both versions of a demo, run the script `run.sh`. This will run Frama-C on both versions, showing the results.
Apart from the expected failures described in each demo, all goals should prove in the fixed version, which runs after the bugged version.
`run.sh` can take arguments. Any arguments it recieves are passed onto Frama-C.

# More Details

Inside each demo is a README giving more information about the demo. This includes information about the codebase, the issue, and how it was fixed.

# Contributing

If you want to modify the patches for a demo, run `setup.sh`. This will put all the changes directly in the repositories, where you can edit them.

Once you've made changes, make a commit (into the demo's repository, not AnnotationsForAll's repository). Then generate a patch like so:

```
git format-patch origin/master --stdout > ../bugged.patch
```

Substitute `../bugged.patch` with `../fixed.patch` if you're altering the fixed repository.

Now if you commit the resultant `.patch` file, it will be the version that gets patched into the result of running `setup.sh`.