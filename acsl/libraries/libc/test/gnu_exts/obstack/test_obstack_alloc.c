#include "../../../test_common.h"
#include <obstack.h>

//@ assigns \result \from \nothing; ensures \result >= 0;
extern int posint();

void runSuccess() {
    struct obstack o;
    obstack_init(&o);

    obstack_alloc(&o, posint());
}

void runFailure() {
    obstack_alloc(NULL, posint());
}

void runFailure1() {
    struct obstack o;
    obstack_init(&o);

    obstack_alloc(&o, anyint());
}

int f;
void testValues() {
    f = 2;
    
    struct obstack o;
    obstack_init(&o);

    int len = posint();
    char* result = obstack_alloc(&o, len);
    //@ assert \valid(result+(0..len-1));

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
