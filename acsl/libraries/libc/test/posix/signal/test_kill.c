#include "../../../test_common.h"
#include <signal.h>

/*@
assigns \result;
*/
extern pid_t anypid();

void runSuccess() {
    kill(anypid(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = kill(anypid(), anyint());
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}