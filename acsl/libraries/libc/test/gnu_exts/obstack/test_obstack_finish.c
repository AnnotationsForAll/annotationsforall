#include "../../../test_common.h"
#include <obstack.h>

//@ assigns \result \from \nothing; ensures \result >= 0;
extern int posint();

void runSuccess() {
    struct obstack o;
    obstack_init(&o);

    obstack_finish(&o);
}

void runFailure() {
    obstack_finish(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct obstack o;
    obstack_init(&o);

    obstack_blank(&o, 4);
    obstack_1grow(&o, '!');
    char* result = obstack_finish(&o);
    //@ assert \valid(result+(0..4));

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
