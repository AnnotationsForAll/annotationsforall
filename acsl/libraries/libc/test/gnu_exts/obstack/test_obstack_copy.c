#include "../../../test_common.h"
#include <obstack.h>

//@ assigns \result \from \nothing; ensures \result >= 0;
extern int posint();

void runSuccess() {
    char buf[] = "s";

    struct obstack o;
    obstack_init(&o);

    obstack_copy(&o, buf, 1);
}

void runSuccess1() {
    struct obstack o;
    obstack_init(&o);

    obstack_copy(&o, anystring(), 0);
}

void runFailure() {
    char buf[] = "s";

    obstack_copy(NULL, buf, 1);
}

void runFailure1() {
    char buf[] = "s";

    struct obstack o;
    obstack_init(&o);

    obstack_copy(&o, buf, 30);
}

int f;
void testValues() {
    f = 2;
    
    char buf[] = "s";

    struct obstack o;
    obstack_init(&o);

    char* result = obstack_copy(&o, buf, 1);
    //@ assert \valid(result);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
