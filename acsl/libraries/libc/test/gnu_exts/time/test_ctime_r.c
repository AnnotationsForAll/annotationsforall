#include "../../../test_common.h"
#include <time.h>

void runSuccess() {
    time_t time;
    char buf[26];
    ctime_r(&time, buf);
}

void runFailure() {
    time_t time;
    char buf[26];
    ctime_r(NULL, buf);
}

void runFailure1() {
    time_t time;
    char buf[26];
    ctime_r(&time, NULL);
}

void runFailure2() {
    time_t time;
    char buf[25];
    ctime_r(&time, buf);
}

int f;
void testValues() {
    f = 2;
    
    time_t time;
    char buf[26];
    char* result = ctime_r(&time, buf);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
