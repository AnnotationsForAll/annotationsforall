#include "../../../test_common.h"
#include <arpa/inet.h>

void runSuccess() {
    char buf[10];
    inet_neta(anyint(), buf, 10);
}

void runFailure() {
    inet_neta(anyint(), NULL, 10);
}

void runFailure1() {
    char buf[10];
    inet_neta(anyint(), buf, 20);
}

int f;
void testValues() {
    f = 2;
    
    char buf[10];
    inet_neta(anyint(), buf, 10);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
