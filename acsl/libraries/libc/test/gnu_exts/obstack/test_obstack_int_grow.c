#include "../../../test_common.h"
#include <obstack.h>

//@ assigns \result \from \nothing; ensures \result >= 0;
extern int posint();

void runSuccess() {
    struct obstack o;
    obstack_init(&o);

    obstack_int_grow(&o, anyint());
}

void runFailure() {
    obstack_int_grow(NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    
    struct obstack o;
    obstack_init(&o);

    obstack_int_grow(&o, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
