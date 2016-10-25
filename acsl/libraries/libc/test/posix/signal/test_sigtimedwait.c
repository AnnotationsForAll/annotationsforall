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

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct timespec * anytime();

void runSuccess() {
    sigtimedwait(anyset(), anyinfo(), anytime());
}

void runFailure() {
    sigtimedwait(NULL, anyinfo(), anytime());
}

void runFailure1() {
    sigtimedwait(anyset(), NULL, anytime());
}

void runFailure2() {
    sigtimedwait(anyset(), anyinfo(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    sigtimedwait(anyset(), anyinfo(), anytime());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
