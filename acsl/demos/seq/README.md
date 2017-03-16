# Bug in seq

## Description of Bug Behavior

<div id="_mcePaste">Formatting 0 length floats causes an out of bounds read:</div>

address@hidden:src$ ./seq -f %0 1
<div id="_mcePaste">./seq: memory exhausted</div>

## Revisions Used

Version with bug: 6.10
## Annotations

Preconditions, and loop annotations were added to long_double_format to prove the generated RTE assertions.

xmalloc in xalloc.c was also annotated because it is used by long_double_format.
## Results

The invariant `strlen(fmt) >= i` in the second loop allows the rte assertion to validate, which checks access to fmt[i]. Without the bug fix, this invariant is not proven. However after the fix, all loop annotations, and rte assertions are proven.

## Modifications & Mitigations

There are four cases where valid_read_string fails as a precondition. In all cases the parameter is a string literal, thus valid. This was left as is because the normal mitigation was too slow in proving, and these are obviously valid.
## References

Bug report: http://lists.gnu.org/archive/html/bug-coreutils/2008-03/msg00181.html

Fix: http://git.savannah.gnu.org/cgit/coreutils.git/commit/?id=b8108fd2ddf77ae79cd014f4f37798a52be13fd1
