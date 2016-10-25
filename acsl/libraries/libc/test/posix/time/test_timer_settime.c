#include "../../../unistd_common.h"
#include <time.h>
#include <signal.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct itimerspec * anytime();

void runSuccess() {
    timer_t timer;
    if (!timer_create(CLOCK_REALTIME, NULL, &timer)) {
        struct itimerspec tm;
        timer_settime(timer, anyint(), anytime(), &tm);
    }
}

void runSuccess1() {
    timer_t timer;
    if (!timer_create(CLOCK_REALTIME, NULL, &timer)) {
        struct itimerspec tm;
        timer_settime(timer, anyint(), anytime(), NULL);
    }
}

void runFailure() {
    timer_t timer;
    if (!timer_create(CLOCK_REALTIME, NULL, &timer)) {
        struct itimerspec tm;
        timer_settime(timer, anyint(), NULL, &tm);
    }
}

int f;
void testValues() {
    f = 2;
    int result;

    timer_t timer;
    if (!timer_create(CLOCK_REALTIME, NULL, &timer)) {
        struct itimerspec tm;
        result = timer_settime(timer, anyint(), anytime(), &tm);
        //@ assert result == 0 || result == -1;
    }
    
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
