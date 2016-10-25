#include "../../../test_common.h"
#include <obstack.h>

//@ assigns \result \from \nothing; ensures \result >= 0;
extern int posint();

void runSuccess() {
    struct obstack o;
    obstack_init(&o);

    obstack_blank(&o, posint());
}

void runFailure() {
    obstack_blank(NULL, posint());
}

void runFailure1() {
    struct obstack o;
    obstack_init(&o);

    obstack_blank(&o, anyint());
}

int f;
void testValues() {
    f = 2;
    
    struct obstack o;
    obstack_init(&o);

    int len = posint();
    obstack_blank(&o, len);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
