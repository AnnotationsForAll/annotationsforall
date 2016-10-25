#include "../../../unistd_common.h"
#include <time.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct timespec * anytime();

void runSuccess() {
    clockid_t id;
    
    int code = clock_setcpuclockid(VALID_PID, &id);
    if (code == 0) {
        clock_settime(id, anytime());
    }
}

void runFailure() {
    clockid_t id;
    
    int code = clock_setcpuclockid(VALID_PID, &id);
    if (code == 0) {
        struct timespec tm;
        clock_settime(id, NULL);
    }
}

int f;
void testValues() {
    f = 2;
    int result;
    clockid_t id;
    
    int code = clock_setcpuclockid(VALID_PID, &id);
    if (code == 0) {
        result = clock_settime(id, anytime());
        //@ assert result == 0 || result == -1;
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
