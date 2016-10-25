#include "../../../test_common.h"
#include <signal.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern sigset_t * anyset();

void runSuccess() {
    sigaddset(anyset(), anyint());
}

void runFailure() {
    sigaddset(NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = sigaddset(anyset(), anyint());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
