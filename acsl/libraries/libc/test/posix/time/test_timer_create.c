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
    timer_create(CLOCK_REALTIME, anysig(), &timer);
}

void runSuccess1() {
    timer_t timer;
    timer_create(CLOCK_REALTIME, NULL, &timer);
}

void runFailure() {
    timer_create(CLOCK_REALTIME, NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    timer_t timer;
    result = timer_create(CLOCK_REALTIME, NULL, &timer);
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
