#include "../../../test_common.h"
#include <obstack.h>

//@ assigns \result \from \nothing; ensures \result >= 0;
extern int posint();

void runSuccess() {
    struct obstack o;
    obstack_init(&o);

    obstack_room(&o);
}

void runFailure() {
    obstack_room(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct obstack o;
    obstack_init(&o);

    int result = obstack_room(&o);
    //@ assert result >= 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
