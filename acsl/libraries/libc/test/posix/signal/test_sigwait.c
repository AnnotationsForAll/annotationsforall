#include "../../../test_common.h"
#include <signal.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern sigset_t * anyset();

void runSuccess() {
    int sig;
    sigwait(anyset(), &sig);
}

void runFailure() {
    int sig;
    sigwait(NULL, &sig);
}

void runFailure1() {
    int sig;
    sigwait(anyset(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    int sig;
    sigwait(anyset(), &sig);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
