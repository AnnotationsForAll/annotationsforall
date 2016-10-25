#include "../../../test_common.h"
#include <obstack.h>

//@ assigns \result \from \nothing; ensures \result >= 0;
extern int posint();

void runSuccess() {
    struct obstack o;
    obstack_init(&o);

    obstack_make_room(&o, posint());
}

void runFailure() {
    obstack_make_room(NULL, posint());
}

void runFailure1() {
    struct obstack o;
    obstack_init(&o);

    obstack_make_room(&o, anyint());
}

int f;
void testValues() {
    f = 2;
    
    struct obstack o;
    obstack_init(&o);

    obstack_make_room(&o, posint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
