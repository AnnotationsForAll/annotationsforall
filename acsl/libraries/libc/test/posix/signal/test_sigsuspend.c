#include "../../../test_common.h"
#include <signal.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern sigset_t * anyset();

void runSuccess() {
    sigsuspend(anyset());
}

void runFailure() {
    sigsuspend(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = sigsuspend(anyset());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
