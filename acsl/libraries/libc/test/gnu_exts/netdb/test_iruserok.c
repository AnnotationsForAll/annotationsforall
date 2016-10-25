#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    iruserok(anyint(), anyint(), anystring(), anystring());
}

void runFailure() {
    iruserok(anyint(), anyint(), NULL, anystring());
}

void runFailure1() {
    iruserok(anyint(), anyint(), anystring(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    iruserok(anyint(), anyint(), anystring(), anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
