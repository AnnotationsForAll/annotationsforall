#include "../../../test_common.h"
#include <obstack.h>

//@ assigns \result \from \nothing; ensures \result >= 0;
extern int posint();

void runSuccess() {
    char buf[] = "s";

    struct obstack o;
    obstack_init(&o);

    obstack_copy0(&o, buf, 1);
}

void runSuccess1() {
    struct obstack o;
    obstack_init(&o);

    obstack_copy0(&o, anystring(), 0);
}

void runFailure() {
    char buf[] = "s";

    obstack_copy0(NULL, buf, 1);
}

void runFailure1() {
    char buf[] = "s";

    struct obstack o;
    obstack_init(&o);

    obstack_copy0(&o, buf, 30);
}

int f;
void testValues() {
    f = 2;
    
    char buf[] = "s";

    struct obstack o;
    obstack_init(&o);

    char* result = obstack_copy0(&o, buf, 1);
    //@ assert \valid(result+(0..1));

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
