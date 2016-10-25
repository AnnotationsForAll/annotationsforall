#include "../../../unistd_common.h"
#include <time.h>

void runSuccess() {
    clockid_t id;
    
    int code = clock_getcpuclockid(VALID_PID, &id);
    if (code == 0) {
        struct timespec tm;
        clock_gettime(id, &tm);
    }
}

void runFailure() {
    clockid_t id;
    
    int code = clock_getcpuclockid(VALID_PID, &id);
    if (code == 0) {
        struct timespec tm;
        clock_gettime(id, NULL);
    }
}

int f;
void testValues() {
    f = 2;
    int result;
    clockid_t id;
    
    int code = clock_getcpuclockid(VALID_PID, &id);
    if (code == 0) {
        struct timespec tm;
        result = clock_gettime(id, &tm);
        //@ assert result == 0 || result == -1;
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
