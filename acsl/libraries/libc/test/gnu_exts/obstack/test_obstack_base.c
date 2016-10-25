#include "../../../test_common.h"
#include <obstack.h>

//@ assigns \result \from \nothing; ensures \result >= 0;
extern int posint();

void runSuccess() {
    struct obstack o;
    obstack_init(&o);

    obstack_base(&o);
}

void runFailure() {
    obstack_base(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct obstack o;
    obstack_init(&o);

    obstack_base(&o);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
