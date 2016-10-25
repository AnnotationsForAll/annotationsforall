#include "../../../test_common.h"
#include <time.h>

void runSuccess() {
    time_t time;
    struct tm res;
    gmtime_r(&time, &res);
}

void runFailure() {
    time_t time;
    struct tm res;
    gmtime_r(NULL, &res);
}

void runFailure1() {
    time_t time;
    struct tm res;
    gmtime_r(&time, NULL);
}

int f;
void testValues() {
    f = 2;
    
    time_t time;
    struct tm res;
    struct tm * result = gmtime_r(&time, &res);
    //@ assert result == \null || *result == res;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
