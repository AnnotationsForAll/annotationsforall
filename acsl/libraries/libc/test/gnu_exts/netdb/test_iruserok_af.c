#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    iruserok_af(anyint(), anyint(), anystring(), anystring(), anyint());
}

void runFailure() {
    iruserok_af(anyint(), anyint(), NULL, anystring(), anyint());
}

void runFailure1() {
    iruserok_af(anyint(), anyint(), anystring(), NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    
    iruserok_af(anyint(), anyint(), anystring(), anystring(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
