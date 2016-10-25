#include "../../../test_common.h"
#include <arpa/inet.h>

void runSuccess() {
    struct in_addr buf;
    inet_aton(anystring(), &buf);
}

void runFailure() {
    struct in_addr buf;
    inet_aton(NULL, &buf);
}

void runFailure1() {
    inet_aton(anystring(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct in_addr buf;
    inet_aton(anystring(), &buf);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
