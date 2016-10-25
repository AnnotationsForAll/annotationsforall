#include "../../../unistd_common.h"
#include <utmp.h>

void runSuccess() {
    struct utmp utmp;
    struct utmpx utmpx;
    getutmp(&utmpx, &utmp);
}

void runFailure() {
    struct utmp utmp;
    struct utmpx utmpx;
    getutmp(NULL, &utmp);
}

void runFailure1() {
    struct utmp utmp;
    struct utmpx utmpx;
    getutmp(&utmpx, NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct utmp utmp;
    struct utmpx utmpx;
    getutmp(&utmpx, &utmp);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
