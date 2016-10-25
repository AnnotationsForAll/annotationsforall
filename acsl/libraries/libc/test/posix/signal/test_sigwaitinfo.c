#include "../../../test_common.h"
#include <signal.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern sigset_t * anyset();

/*@
assigns \result;
ensures \valid(\result);
*/
extern siginfo_t * anyinfo();

void runSuccess() {
    sigwaitinfo(anyset(), anyinfo());
}

void runFailure() {
    sigwaitinfo(NULL, anyinfo());
}

void runFailure1() {
    sigwaitinfo(anyset(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    sigwaitinfo(anyset(), anyinfo());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
