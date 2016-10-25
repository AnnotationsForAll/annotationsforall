#include "../../../unistd_common.h"
#include <utmp.h>

void runSuccess() {
    utmpxname(anystring());
}

void runFailure() {
    utmpxname(NULL);
}

int f;
void testValues() {
    f = 2;
    
    utmpxname(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
