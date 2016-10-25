#include "../../../test_common.h"
#include <obstack.h>

//@ assigns \result \from \nothing; ensures \result >= 0;
extern int posint();

void runSuccess() {
    struct obstack o;
    obstack_init(&o);

    obstack_object_size(&o);
}

void runFailure() {
    obstack_object_size(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct obstack o;
    obstack_init(&o);

    obstack_blank(&o, 4);
    obstack_1grow(&o, '!');
    int result = obstack_object_size(&o);
    //@ assert result == 5;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
