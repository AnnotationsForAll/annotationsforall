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
        timer_delete(timer);
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
        result = timer_delete(timer);
        //@ assert result == 0 || result == -1;
    }
    
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
