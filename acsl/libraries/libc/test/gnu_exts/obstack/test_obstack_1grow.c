#include "../../../test_common.h"
#include <obstack.h>

//@ assigns \result \from \nothing; ensures \result >= 0;
extern int posint();

void runSuccess() {
    struct obstack o;
    obstack_init(&o);

    obstack_1grow(&o, anyint());
}

void runFailure() {
    obstack_1grow(NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    
    struct obstack o;
    obstack_init(&o);

    obstack_1grow(&o, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
