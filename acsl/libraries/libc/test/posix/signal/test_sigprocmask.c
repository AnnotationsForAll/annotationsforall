#include "../../../test_common.h"
#include <signal.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern sigset_t * anyset();

void runSuccess() {
    sigprocmask(anyint(), anyset(), anyset());
}

void runFailure() {
    sigprocmask(anyint(), NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = sigprocmask(anyint(), anyset(), anyset());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
