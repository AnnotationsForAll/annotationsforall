#include "../../../test_common.h"
#include <obstack.h>

//@ assigns \result \from \nothing; ensures \result >= 0;
extern int posint();

void runSuccess() {
    struct obstack o;
    obstack_init(&o);

    obstack_memory_used(&o);
}

void runFailure() {
    obstack_memory_used(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct obstack o;
    obstack_init(&o);

    int result = obstack_memory_used(&o);
    //@ assert result >= 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
