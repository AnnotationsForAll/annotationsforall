#include "../../../unistd_common.h"
#include <time.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct timespec * anytime();

void runSuccess() {
    clockid_t id;
    
    int code = clock_getcpuclockid(VALID_PID, &id);
    if (code == 0) {
        struct timespec tm;
        clock_nanosleep(id, anyint(), anytime(), &tm);
    }
}

void runSuccess1() {
    clockid_t id;
    
    int code = clock_getcpuclockid(VALID_PID, &id);
    if (code == 0) {
        clock_nanosleep(id, anyint(), anytime(), NULL);
    }
}

void runFailure() {
    clockid_t id;
    
    int code = clock_getcpuclockid(VALID_PID, &id);
    if (code == 0) {
        struct timespec tm;
        clock_nanosleep(id, anyint(), NULL, &tm);
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
        struct timespec * arg = anytime();
        result = clock_nanosleep(id, anyint(), arg, &tm);
        //@ assert times_gte: result == 0 ==> (tm.tv_sec*1000000000+tm.tv_nsec >= arg->tv_sec*1000000000+arg->tv_nsec);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
