#include "../../../test_common.h"
#include <poll.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct pollfd * anyfds();

void runSuccess() {
    struct timespec tmo;
    sigset_t sig;
    ppoll(anyfds(), 1, &tmo, &sig);
}

void runSuccess1() {
    struct timespec tmo;
    sigset_t sig;
    ppoll(anyfds(), 1, NULL, &sig);
}

void runSuccess2() {
    struct timespec tmo;
    sigset_t sig;
    ppoll(anyfds(), 1, &tmo, NULL);
}

void runSuccess3() {
    struct timespec tmo;
    sigset_t sig;
    ppoll(anyfds(), 1, NULL, NULL);
}

void runFailure() {
    struct timespec tmo;
    sigset_t sig;
    ppoll(NULL, 1, &tmo, &sig);
}

int f;
void testValues() {
    f = 2;

    struct timespec tmo;
    sigset_t sig;
    int result = ppoll(anyfds(), 1, &tmo, &sig);
    //@ assert result >= -1;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
