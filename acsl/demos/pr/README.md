# Bug in pr

## Description of Bug Behavior

The code fails when, before a tab (\t), the number of backspaces (\b) exceeds the number of characters that can be removed. The failure happens on line 2693 when the macro TAB_WIDTH gets a negative value for the input_position variable (the position for the next character to be written). Thus, the macro returns a value that is larger than the size of array clump_buff and the variable width (gets its value from the macro) exceeds the size of the buffer. This bug can be found at version 6.10.

## Revisions Used

Repository: git://git.sv.gnu.org/coreutils.git

Version with bug
   * Version 6.10
   * Commit: 1440ca24fd216bb3a4d7c388b23a9512a4585508
   * Mon, 21 Jan 2008 23:31:02 +0000 (00:31 +0100)
   
First presence
   * Initial commit of file
   * Commit: b25038ce9a234ea0906ddcbd8a0012e917e6c661
   * Sun, 8 Nov 1992 02:50:43 +0000 (02:50 +0000)
   
Initial fix
   * Commit: 6856089f7bfaca2709b303f01dae001a30930b61
   * Sat, 19 Apr 2008 11:34:38 +0000 (13:34 +0200)
   
## Description of Bug

A global variable _input_position_ is used to track the horizontal position in a file. This position is used to convert special characters such as tabs, which will have multiple spaces, and backspaces, which have a negative space. However, because <em>input_position </em>represents the position in a file, it does not make sense for the value to be less than zero, and the bug occurs when this variable is negative.

## Annotations

A predicate was defined to represent a invariant for _input_position_.

```
/*@ predicate valid_input_position = (input_position >= 0); */
```

This predicate was then added as a pre and post condition to the function _char_to_clump_, which is responsible for converting characters to the proper format, and incrementing or decrementing _input_position_ by the width.

```
/*@
requires valid_input_position; 
ensures valid_input_position;
*/
```

Noting that the function _read_line_ also modifies _input_position_, and makes calls to _char_to_clump_, the same contract was added to _read_line_ to show it preserves the invariant.

## Results

With the annotations applied on version 6.10, the only goal which is not validated is the post-condition of _char_to_clump_. Validation of the function _read_line_ show that it both preserves the invariant, and makes valid calls to _char_to_clump_. However, failing to validate _char_to_clump_ indicates the function may not preserve the invariant.

After applying the fix in commit 6856089f7bfaca2709b303f01dae001a30930b61, all of the goals are validated.

## Modifications & Mitigations

The c11 feature _Static_assert is used, but frama-c only supports c99. The statement using this feature was removed from the file lib/verify.h.

A global invariant would have been used to check valid_input_position, but the feature is not well supported. Instead, the invariant was added to the pre and post condition of functions being analyzed.

## References

@inproceedings{cadar2008klee, <br /> title={KLEE: Unassisted and Automatic Generation of High-Coverage Tests for Complex Systems Programs.}, <br /> author={Cadar, Cristian and Dunbar, Daniel and Engler, Dawson R}, <br /> booktitle={OSDI}, <br /> volume={8}, <br /> pages={209--224}, <br /> year={2008} <br /> } <br /> <br /> @inproceedings{zuddas2014mimic, <br /> title={MIMIC: locating and understanding bugs by analyzing mimicked executions}, <br /> author={Zuddas, Daniele and Jin, Wei and Pastore, Fabrizio and Mariani, Leonardo and Orso, Alessandro}, <br /> booktitle={Proceedings of the 29th ACM/IEEE international conference on Automated software engineering}, <br /> pages={815--826}, <br /> year={2014}, <br /> organization={ACM} <br /> }
