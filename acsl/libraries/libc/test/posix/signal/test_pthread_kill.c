#include "../../../test_common.h"
#include <signal.h>

/*@
assigns \result;
*/
extern pthread_t anypid();

void runSuccess() {
    pthread_kill(anypid(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    pthread_kill(anypid(), anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
