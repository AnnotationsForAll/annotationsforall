#include "../../../test_common.h"
#include <obstack.h>

//@ assigns \result \from \nothing; ensures \result >= 0;
extern int posint();

void runSuccess() {
    struct obstack o;
    obstack_init(&o);

    if (obstack_room(&o) >= sizeof(char)) {
        obstack_1grow_fast(&o, anyint());
    }
}

void runFailure() {
    obstack_1grow_fast(NULL, anyint());
}

void runFailure1() {
    struct obstack o;
    obstack_init(&o);

    obstack_1grow_fast(&o, anyint());
}

int f;
void testValues() {
    f = 2;
    
    struct obstack o;
    obstack_init(&o);

    if (obstack_room(&o) >= sizeof(char)) {
        obstack_1grow_fast(&o, anyint());
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
