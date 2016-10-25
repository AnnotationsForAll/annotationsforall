#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    ruserok_af(anystring(), anyint(), anystring(), anystring(), anyint());
}

void runFailure() {
    ruserok_af(anystring(), anyint(), NULL, anystring(), anyint());
}

void runFailure1() {
    ruserok_af(anystring(), anyint(), anystring(), NULL, anyint());
}

void runFailure2() {
    ruserok_af(NULL, anyint(), anystring(), anystring(), anyint());
}

int f;
void testValues() {
    f = 2;
    
    ruserok_af(anystring(), anyint(), anystring(), anystring(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
