#include "../../../unistd_common.h"
#include <time.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct timespec * anytime();

void runSuccess() {
    clockid_t id;
    
    struct timespec tm;
    nanosleep(anytime(), &tm);
}

void runSuccess1() {
    clockid_t id;
    
    nanosleep(anytime(), NULL);
}

void runFailure() {
    clockid_t id;
    
    struct timespec tm;
    nanosleep(NULL, &tm);
}

int f;
void testValues() {
    f = 2;
    int result;
    clockid_t id;
    
    struct timespec tm;
    struct timespec * arg = anytime();
    result = nanosleep(arg, &tm);
    //@ assert times_gte: result == 0 ==> (tm.tv_sec*1000000000+tm.tv_nsec >= arg->tv_sec*1000000000+arg->tv_nsec);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
