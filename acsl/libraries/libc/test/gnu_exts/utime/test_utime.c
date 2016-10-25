#include "../../../unistd_common.h"
#include <utime.h>

void runSuccess() {
    struct utimbuf time;
    utime(anystring(), &time);
}

void runSuccess1() {
    utime(anystring(), NULL);
}

void runFailure() {
    struct utimbuf time;
    utime(NULL, &time);
}

int f;
void testValues() {
    f = 2;
    
    struct utimbuf time;
    utime(anystring(), &time);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
