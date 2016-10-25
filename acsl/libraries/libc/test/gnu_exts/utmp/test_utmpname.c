#include "../../../test_common.h"
#include <utmp.h>

void runSuccess() {
    utmpname(anystring());
}

void runFailure() {
    utmpname(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    utmpname(anystring());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
