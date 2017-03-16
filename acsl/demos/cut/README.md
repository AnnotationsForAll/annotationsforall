# Bug in cut

## Description of Bug Behavior

http://debbugs.gnu.org/cgi/bugreport.cgi?msg=5;att=0;bug=13627

Can reproduce with command:

```
echo '' | ./src/cut --output-d=: -b1,1234567890-
```
## Revisions Used

Repository: git://git.sv.gnu.org/coreutils.git

Version with bug
   * Commit: d57ebc45ba4c59cc6f8bb0e9a435ecbddc84b982
   * Fri, 1 Feb 2013 21:33:21 +0000
   
Introduced
   * Commit: ec48beadfa0ae1216788eaf6bf558ee2013eac18
   * Thu, 6 Dec 2012 18:29:23 +0000
   
Initial fix
   * Commit: be7932e863de07c4c7e4fc3c1db3eb6d04ba9af5
   * Mon, 4 Feb 2013 13:55:01 +0000

## Description of Bug

The function set_fields allocates the printable_field array. This function calls is_printable_field which assumes the argument refers to a valid location in printable_field. However this precondition cannot be guaranteed, and the test case will cause a segmentation fault due to attempting to access a value past the array bounds.
## Annotations

Contracts were added to required functions from gnulib by adding headers.

```
/*@ requires s>0;
ensures \valid((unsigned char *)\result+(0..(s-1)));
*/
extern void *xzalloc(size_t s);
/*@ assigns *table; */
extern void *hash_insert (Hash_table *table, void const *entry); 
```

Minimal contracts were added to some functions used by<em> set_fields</em>.

```
/*@ assigns *range_start_ht; */
static inline void mark_range_start (size_t i)

/*@ assigns printable_field[i/8]; */
static inline void mark_printable_field (size_t i)

/*@ requires \valid(printable_field+(i/8));
assigns \nothing;
*/
static inline bool is_printable_field (size_t i)
```

In the function _set_fields_, properties of the variable _max_range_endpoint_ are discovered through a loop invariant.

```
max_range_endpoint = 0;
//@ ghost size_t max_range_endpoint_old = max_range_endpoint;
/*@
loop assigns i, max_range_endpoint, max_range_endpoint_old;
// max_range_endpoint only increases
loop invariant max_range_endpoint >= max_range_endpoint_old;
// max_range_endpoint is max of rp[..].hi
loop invariant \forall integer idx; (0 <= idx < i) ==> (max_range_endpoint > rp[idx].hi);
loop variant n_rp - i;
*/
for (i = 0; i &lt; n_rp; i++)
{
//@ ghost max_range_endpoint_old = max_range_endpoint;
if (rp[i].hi > max_range_endpoint)
max_range_endpoint = rp[i].hi;
}
```

It is now known that at the end of the loop, _max_range_endpoint_ holds the maximum _hi_ value from the _rp_ array.

Additional annotations are added to later loops to show variable _max_range_endpoint_ is unchanged, and maintains the relationship with _printable_field_.

```
/*@ loop assigns i, *range_start_ht, printable_field[0 .. (max_range_endpoint/8)]; */

/*@ loop assigns j, printable_field[0 .. (max_range_endpoint/8)]; */ 
```

When validating the pre-condition to _is_printable_field_, wp was having difficulty, so a lemma was added. The lemma validates, indicating it is always true.

```
/*@
lemma Inner_Printable_Field_Validity:
(max_range_endpoint ==> \valid(printable_field+(0..(max_range_endpoint / 8)))) ==>
(max_range_endpoint ==> (((0 &lt;= eol_range_start &lt;= max_range_endpoint)) ==> \valid(printable_field+(eol_range_start / 8))));
*/
```

## Results

Earlier in the function, a relationship is formed between _max_range_endpoint_ and the allocated size of _printable_field_.

```
if (max_range_endpoint)
printable_field = xzalloc (max_range_endpoint / CHAR_BIT + 1);
```

The later loops are annotated with assigns to preserve this property. The code below shows the error.

```
if (output_delimiter_specified
&& !complement
&& eol_range_start
&& max_range_endpoint 
&& !is_printable_field (eol_range_start))
mark_range_start (eol_range_start);
```

Even though _max_range_endpoint_ is checked, the restrictions are not strong enough. The call to _is_printable_field_ requires the parameter to reference a valid index of _printable_field_, and we have insufficient information on _eol_range_start_ to make that claim. The fix adds a condition relating _eol_range_start_ to<em> max_range_endpoint</em>, which we have already established is related to the size of _printable_field_.

```
if (output_delimiter_specified
&& !complement
&& eol_range_start
&& max_range_endpoint
&& (max_range_endpoint &lt; eol_range_start
|| !is_printable_field (eol_range_start)))
mark_range_start (eol_range_start);
```
As expected, the precondition on<em> is_printable_field</em> in the original code does not validate, but does validate once the fix is applied. Furthermore, when assuming the contracts provided for the functions in gnulib, the contracts for _mark_range_start_, _mark_printable_field_, and _is_printable_field_ validate. Additionally, all but one of the loops validates.

```
/*@ loop assigns j, printable_field[0 .. (max_range_endpoint/8)]; */
for (size_t j = rp[i].lo; j &lt;= rp[i].hi; j++)
    mark_printable_field (j); 
```

The code above does not validate with frama-c, but is true. Adding the invariant `j >= 0` validates, so the loop variable range is `0 <= j <= rp[i].hi`, where `0 <= i < n_rp` from an outer loop. Additionally, the previous loop held the invariant `\forall integer idx; (0 <= idx < n_rp) ==> (max_range_endpoint >= rp[idx].hi)`, or `max_range_endpoint` is the largest <em>hi </em>value in <em>rp </em>. Therefore, the largest possible range for<em> j </em>is `0 <= j <= max_range_endpoint`. The single function called in this loop with argument <em>arg </em>assigns `printable_field[arg/8]`. Therefore, the worst case assignments from this loop is<em> printable_field</em> with indexes `j/8`, which is bounded by `0 <= j/8 <= max_range_endpoint/8`. This is written as `printable_field[0 .. (max_range_endpoint/8)]`.

## Modifications & Mitigations

Removed _Static_assert calls from gnulib/lib/verify.h to comply with C99.

Used Typed+cast model because of the pointer type conversions required.

## Expected Failures

Some goals do not prove:
   * typed_cast_set_fields_loop_assign_3_part3: This loop assignment is valid, but cannot be proven.

Other goals cannot prove due to the use of undefined bahvior when assigning to some variables:
   * typed_cast_set_fields_call_strspn_pre_valid_string_src
   * typed_cast_set_fields_call_free_deallocation_pre_freeable
   * typed_cast_set_fields_call_qsort_pre
   * typed_cast_set_fields_call_free_deallocation_pre_freeable_2
