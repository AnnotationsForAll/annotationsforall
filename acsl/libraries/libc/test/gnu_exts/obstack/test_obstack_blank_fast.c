#include "../../../test_common.h"
#include <obstack.h>

//@ assigns \result \from \nothing; ensures \result >= 0;
extern int posint();

void runSuccess() {
    struct obstack o;
    obstack_init(&o);

    int len = posint();
    if (obstack_room(&o) >= len) {
        obstack_blank_fast(&o, len);
    }
}

void runFailure() {
    obstack_blank(NULL, posint());
}

void runFailure1() {
    struct obstack o;
    obstack_init(&o);

    int len = posint();
    obstack_blank_fast(&o, len);
}

int f;
void testValues() {
    f = 2;
    
    struct obstack o;
    obstack_init(&o);

    int len = posint();
    if (obstack_room(&o) >= len) {
        obstack_blank_fast(&o, len);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
