#include "../../../unistd_common.h"
#include <time.h>

void runSuccess() {
    clockid_t id;
    
    clock_getcpuclockid(VALID_PID, &id);
}

void runFailure() {
    clock_getcpuclockid(VALID_PID, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    clockid_t id;
    
    result = clock_getcpuclockid(VALID_PID, &id);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
