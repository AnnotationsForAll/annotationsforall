#include "../../../unistd_common.h"
#include <utmp.h>

void runSuccess() {
    struct utmp utmp;
    struct utmpx utmpx;
    getutmpx(&utmp, &utmpx);
}

void runFailure() {
    struct utmp utmp;
    struct utmpx utmpx;
    getutmpx(NULL, &utmpx);
}

void runFailure1() {
    struct utmp utmp;
    struct utmpx utmpx;
    getutmpx(&utmp, NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct utmp utmp;
    struct utmpx utmpx;
    getutmpx(&utmp, &utmpx);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
