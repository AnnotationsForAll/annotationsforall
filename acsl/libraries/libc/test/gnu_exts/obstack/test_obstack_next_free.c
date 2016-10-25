#include "../../../test_common.h"
#include <obstack.h>

//@ assigns \result \from \nothing; ensures \result >= 0;
extern int posint();

void runSuccess() {
    struct obstack o;
    obstack_init(&o);

    obstack_next_free(&o);
}

void runFailure() {
    obstack_next_free(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct obstack o;
    obstack_init(&o);

    obstack_next_free(&o);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
