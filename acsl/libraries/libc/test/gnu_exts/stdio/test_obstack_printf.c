#include "../../../stdio_common.h"
#include <stdio.h>
#include <obstack.h>

void runSuccess() {
    struct obstack o;
    obstack_init(&o);
    obstack_printf(&o, anystring());
}

void runFailure() {
    obstack_printf(NULL, anystring());
}

void runFailure1() {
    struct obstack o;
    obstack_init(&o);
    obstack_printf(&o, NULL);
}


int f;
void testValues() {
    f = 2;
    
    struct obstack o;
    obstack_init(&o);
    obstack_printf(&o, anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
