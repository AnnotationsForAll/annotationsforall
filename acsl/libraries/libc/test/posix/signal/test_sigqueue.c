#include "../../../test_common.h"
#include <signal.h>

/*@
assigns \result;
*/
extern pid_t anypid();

/*@
assigns \result;
*/
extern union sigval anyval();

void runSuccess() {
    sigqueue(anypid(), anyint(), anyval());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = sigqueue(anypid(), anyint(), anyval());
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
