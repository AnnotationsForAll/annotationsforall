#include "../../../test_common.h"
#include <obstack.h>

//@ assigns \result \from \nothing; ensures \result >= 0;
extern int posint();

void runSuccess() {
    struct obstack o;
    obstack_init(&o);

    if (obstack_room(&o) >= sizeof(void*)) {
        obstack_ptr_grow_fast(&o, anystring());
    }
}

void runSuccess1() {
    struct obstack o;
    obstack_init(&o);

    if (obstack_room(&o) >= sizeof(void*)) {
        obstack_ptr_grow_fast(&o, NULL);
    }
}

void runFailure() {
    obstack_ptr_grow_fast(NULL, anystring());
}

void runFailure1() {
    struct obstack o;
    obstack_init(&o);

    obstack_ptr_grow_fast(&o, anystring());
}

int f;
void testValues() {
    f = 2;
    
    struct obstack o;
    obstack_init(&o);

    if (obstack_room(&o) >= sizeof(void*)) {
        obstack_ptr_grow_fast(&o, anystring());
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
