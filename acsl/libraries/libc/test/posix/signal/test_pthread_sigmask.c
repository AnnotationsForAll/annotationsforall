#include "../../../test_common.h"
#include <signal.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern sigset_t * anyset();

void runSuccess() {
    pthread_sigmask(anyint(), anyset(), anyset());
}

void runFailure() {
    pthread_sigmask(anyint(), NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    pthread_sigmask(anyint(), anyset(), anyset());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
