#include "../../../unistd_common.h"
#include <time.h>
#include <signal.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct sigevent * anysig();

void runSuccess() {
    timer_t timer;
    if (!timer_create(CLOCK_REALTIME, anysig(), &timer)) {
        struct itimerspec tm;
        timer_gettime(timer, &tm);
    }
}

void runFailure() {
    timer_t timer;
    if (!timer_create(CLOCK_REALTIME, anysig(), &timer)) {
        struct itimerspec tm;
        timer_gettime(timer, NULL);
    }
}

int f;
void testValues() {
    f = 2;
    int result;

    timer_t timer;
    if (!timer_create(CLOCK_REALTIME, anysig(), &timer)) {
        struct itimerspec tm;
        timer_gettime(timer, &tm);
    }
    
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
