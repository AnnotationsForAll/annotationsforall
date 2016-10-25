#include "../../../test_common.h"
#include <obstack.h>

//@ assigns \result \from \nothing; ensures \result >= 0;
extern int posint();

void runSuccess() {
    struct obstack o;
    obstack_init(&o);
}

void runFailure() {
    obstack_init(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct obstack o;
    obstack_init(&o);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
