#ifndef TESTS_EXTRA_AXIOMS_H_
#define TESTS_EXTRA_AXIOMS_H_

#include <stddef.h>
#include <limits.h>

/*@
axiomatic IntCast {
    logic int to_int(integer x);
    predicate is_int(integer x);
    
    axiom to_int_prop: \forall integer x; (int)x == to_int(x);
    axiom to_int_id: \forall integer x; is_int(x) ==> to_int(x) == x;
    
    axiom is_int_id: \forall integer x; (INT_MIN <= x <= INT_MAX) ==> is_int(x);
}

axiomatic LongCast {
    logic long int to_long(integer x);
    predicate is_long(integer x);
    
    axiom to_long_prop: \forall integer x; (long int)x == to_long(x);
    axiom to_long_id: \forall integer x; is_long(x) ==> to_long(x) == x;
    
    axiom is_long_id: \forall integer x; (LONG_MIN <= x <= LONG_MAX) ==> is_long(x);
}

axiomatic LLongCast {
    logic long long int to_llong(integer x);
    predicate is_llong(integer x);
    
    axiom to_llong_prop: \forall integer x; (long long int)x == to_llong(x);
    axiom to_llong_id: \forall integer x; is_llong(x) ==> to_llong(x) == x;
    
    axiom is_llong_id: \forall integer x; (LLONG_MIN <= x <= LLONG_MAX) ==> is_llong(x);
}

axiomatic CharCast {
    logic char to_char(integer x);
    predicate is_char(integer x);
    
    axiom to_char_prop: \forall integer x; (char)x == to_char(x);
    axiom to_char_id: \forall integer x; is_char(x) ==> to_char(x) == x;
    
    axiom is_char_id: \forall integer x; (CHAR_MIN <= x <= CHAR_MAX) ==> is_char(x);
}
*/

#endif
