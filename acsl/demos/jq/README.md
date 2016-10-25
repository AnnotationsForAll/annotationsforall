# Description

This is a proof that a bug existed in the codebase of JQ, a JSON parser library written in C.
The issue we are checking for is [#896](https://github.com/stedolan/jq/issues/896).

# Running

Not all goals will pass in the correct version. These are the ones that may fail:

* `*_assert_separation`: Seperation logic of allocation cannot be currently expressed in Frama-C, so asserts are used instead.
* `*_assert_vac`: The vaccuous test. If it proves, then there is a condradiction in logic allowing \false to be provable.
* `*_assert_bug_correction`: This is an assert to offset the bug [desrcibed here](https://bts.frama-c.com/view.php?id=2234).
* `jv_get_call_jv_free_pre_6`: Despite successfully asserting the preconditons for jv_free directly above it, the preconditions for this function will not prove. Possible Frama-C bug.

All other goals are expected to pass.

# Details

See `jv_aux.c` in both versions for more details about the proof.
