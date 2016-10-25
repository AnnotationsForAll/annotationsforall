#include "../../../test_common.h"
#include <signal.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern sigset_t * anyset();

void runSuccess() {
    sigdelset(anyset(), anyint());
}

void runFailure() {
    sigdelset(NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = sigdelset(anyset(), anyint());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
