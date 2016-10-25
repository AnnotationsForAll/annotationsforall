#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    ruserok(anystring(), anyint(), anystring(), anystring());
}

void runFailure() {
    ruserok(anystring(), anyint(), NULL, anystring());
}

void runFailure1() {
    ruserok(anystring(), anyint(), anystring(), NULL);
}

void runFailure2() {
    ruserok(NULL, anyint(), anystring(), anystring());
}

int f;
void testValues() {
    f = 2;
    
    ruserok(anystring(), anyint(), anystring(), anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
