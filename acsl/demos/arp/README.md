# Bug in arp

## Description of Bug Behavior

Running _busybox arp -Ainet_ in version 1.6.2 results in _Segmentation fault._
## Version used

Version with bug
   * Version 1.6.2
   * Avaliable at http://www.busybox.net/downloads/
   
## Description of Bug

The bug can be found on line 454 in the int <em>arp_main </em>method. Since neither the H nor t option was given in the command line, _hw_type_ was set to Null. Thus, in line 462 we have a Null passed to _get_hwtype_. This value is then used in a call to _strcmp_. The behaviour of _strcmp_ is not defined for invalid strings, so this call should be avoided.

## Annotations

No annotations are required for the function _arp_main_, which contains the error.

The function _get_hwtype_ was annotated with a pre-condition to require a valid argument.

```
/*@ requires valid_name: \valid(name); */
```

Additionally, a loop inside _get_hwtype_ was annotated with invariants and a variant to show calls to <em>strcmp </em>satisfy it's pre-condition.

```
//@ ghost const struct hwtype *const *hwp_orrig = hwp; 
//@ ghost int hwp_offset = 0;
/*@
loop assigns hwp, hwp_offset;
loop invariant \valid(name); 
loop invariant hwp == hwp_orrig + hwp_offset;
loop invariant 0 <= hwp_offset <= hwtypes_size;
loop variant hwp_orrig+hwtypes_size - hwp;
*/
while (*hwp != NULL) {
  if (!strcmp((*hwp)->name, name))
    return (*hwp);
  hwp++; 
  //@ ghost hwp_offset++;
}

```
Annotations relating to the global variable <em>hwtypes[] </em>were added. First, a logical integer was declared setting the known size.

```
/*@ 
axiomatic HWTypes { 
logic integer hwtypes_size{L};
axiom hwtypes_const_len{L}: hwtypes_size == 5;
}
*/
```

Next, a global invariant was defined showing some properties of the structure.
```
/*@
global invariant hwtype_structure:
\valid(hwtypes+(0..hwtypes_size))
&& \forall integer i; (0 <= i < hwtypes_size) ==>; (\valid(*(hwtypes+i)))
&& \forall integer i; (0 <= i < hwtypes_size) ==> (\valid((*(hwtypes+i))->name))
&& *(hwtypes+hwtypes_size) 0;
*/
```
Minimal contracts were added for functions called in arp_main.

A contract was added to _get_aftype_ showing it does not have any side effects.

```
/*@ assigns \nothing; */
```
A post-condition of false was added to _bb_error_msg_and_die_, which exits, and does not return from the function in any case.

```
/*@ ensures \false; */
```

## Results

Below is a section of code from arp_main. The error is in the second conditional, which should be checking ARP_OPT_H, and ARP_OPT_t. As is, the call to get_hwtype may have a null argument. When corrected, hw_type is known to be valid, because of the relationship defined by getopt32_arp.

```
getopt32_arp(argc, argv, "A:p:H:t:i:adnDsv", &protocol, &protocol,

&hw_type, &hw_type, &device);

argv += optind;

if (option_mask32 & ARP_OPT_A || option_mask32 & ARP_OPT_p) {

ap = get_aftype(protocol);

if (ap == NULL)

bb_error_msg_and_die("%s: unknown %s", protocol, "address family");

}

if (option_mask32 & ARP_OPT_A || option_mask32 & ARP_OPT_p) {

hw = get_hwtype(hw_type);

if (hw == NULL)

bb_error_msg_and_die("%s: unknown %s", hw_type, "hardware type");

hw_set = 1;


}
```

A precondition required by get_hwtype in arp_main fails, indicating the possible error. The bug exists because incorrect flags are being checked. By fixing this error, arp_main is validated completely.

The function get_hwtype is validated completely, when assuming the correct properties of hwtypes[].

## Modifications & Mitigations

The definition of <em>strlen </em>provided by frama-c's libc headers while correct, was too difficult to be proven in several instances. To have a useable definition, the specification was weakened by changing the pre-condition from the _valid_string_ predicate, to the built in _\valid_.

String literals were refactored as needed to instead use a temporary variable, because <em>\valid </em>was incorrectly failing.

Added function _getopt32_arp_ which proxies to <em>getopt32 </em>specifically for the _arp_main_ function, because <em>getopt32 </em>uses a variable argument list. Because of the setup, the annotations are not proven, but provides a contract which can be assumed.

```
/*@
   ensures \result == option_mask32;
   ensures (option_mask32 & (0x1)) <==> \valid(*protocol); // ARP_OPT_A
   ensures (option_mask32 & (0x2)) <==> \valid(*protocol2); // ARP_OPT_p
   ensures (option_mask32 & (0x4)) <==> \valid(*hw_type); // ARP_OPT_H
   ensures (option_mask32 & (0x8)) <==> \valid(*hw_type2); // ARP_OPT_t
*/
```

Because global invariants are not well supported, the property was simply asserted at the beginning of get_hwtype.

```
//@ assert \valid(hwtypes+(0..hwtypes_size));
//@ assert \forall integer i; (0 <= i < hwtypes_size) ==> (\valid(*(hwtypes+i)));
//@ assert \forall integer i; (0 <= i < hwtypes_size) ==> (\valid((*(hwtypes+i))->name));
//@ assert *(hwtypes+hwtypes_size) == 0;
```
## <a name="References"></a> References

@inproceedings{ray2011debugging,

title={Debugging memory issues in embedded linux: a case study},

author={Ray, Partha Pratim and Banerjee, Ansuman},

booktitle={Students' Technology Symposium (TechSym), 2011 IEEE},

pages={23--28},

year={2011},

organization={IEEE}

}
