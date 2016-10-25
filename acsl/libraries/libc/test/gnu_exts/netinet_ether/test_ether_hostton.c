#include "../../../test_common.h"
#include <netinet/ether.h>

void runSuccess() {
    struct ether_addr addr;
    ether_hostton(anystring(), &addr);
}

void runFailure() {
    struct ether_addr addr;
    ether_hostton(NULL, &addr);
}

void runFailure1() {
    struct ether_addr addr;
    ether_hostton(anystring(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct ether_addr addr;
    ether_hostton(anystring(), &addr);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
