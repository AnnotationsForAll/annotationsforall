#include "../../../test_common.h"
#include <time.h>

void runSuccess() {
    struct tm time;
    getdate_r(anystring(), &time);
}

void runFailure() {
    struct tm time;
    getdate_r(NULL, &time);
}

void runFailure1() {
    struct tm time;
    getdate_r(anystring(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct tm time;
    int result = getdate_r(anystring(), &time);
    //@ assert result >= 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
