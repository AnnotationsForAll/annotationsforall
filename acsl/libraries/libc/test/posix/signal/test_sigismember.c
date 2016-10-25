#include "../../../test_common.h"
#include <signal.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern sigset_t * anyset();

void runSuccess() {
    sigismember(anyset(), anyint());
}

void runFailure() {
    sigismember(NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = sigismember(anyset(), anyint());
    //@ assert result == -1 || result == 0 || result == 1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
