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
        timer_getoverrun(timer);
    }
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;

    timer_t timer;
    if (!timer_create(CLOCK_REALTIME, anysig(), &timer)) {
        result = timer_getoverrun(timer);
    }
    
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
