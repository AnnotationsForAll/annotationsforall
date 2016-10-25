#include "../../../test_common.h"
#include <signal.h>

void runSuccess() {
    struct sigvec v;
    struct sigvec ov;
    sigvec(anyint(), &v, &ov);
}

void runSuccess1() {
    struct sigvec v;
    struct sigvec ov;
    sigvec(anyint(), &v, NULL);
}

void runSuccess2() {
    struct sigvec v;
    struct sigvec ov;
    sigvec(anyint(), NULL, &ov);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    struct sigvec v;
    struct sigvec ov;
    sigvec(anyint(), &v, &ov);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
