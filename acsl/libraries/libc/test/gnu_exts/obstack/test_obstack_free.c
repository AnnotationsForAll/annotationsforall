#include "../../../test_common.h"
#include <obstack.h>

//@ assigns \result \from \nothing; ensures \result >= 0;
extern int posint();

void runSuccess() {
    struct obstack o;
    obstack_init(&o);

    obstack_free(&o, NULL);
}

void runSuccess1() {
    struct obstack o;
    obstack_init(&o);

    char* elem = obstack_alloc(&o, posint());
    obstack_free(&o, elem);
}

void runFailure() {
    obstack_free(NULL, NULL);
}

void runFailure1() {
    struct obstack o;
    obstack_init(&o);

    obstack_free(&o, NULL);

    obstack_alloc(&o, posint());
}

int f;
void testValues() {
    f = 2;
    
    struct obstack o;
    obstack_init(&o);

    char* elem = obstack_alloc(&o, posint());
    obstack_free(&o, elem);

    obstack_free(&o, NULL);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
