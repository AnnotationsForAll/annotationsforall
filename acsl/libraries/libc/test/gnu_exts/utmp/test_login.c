#include "../../../test_common.h"
#include <utmp.h>

void runSuccess() {
    struct utmp u;
    login(&u);
}

void runFailure() {
    login(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    struct utmp u;
    login(&u);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
