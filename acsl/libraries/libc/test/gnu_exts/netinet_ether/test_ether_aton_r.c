#include "../../../test_common.h"
#include <netinet/ether.h>

void runSuccess() {
    struct ether_addr addr;
    ether_aton_r(anystring(), &addr);
}

void runFailure() {
    struct ether_addr addr;
    ether_aton_r(NULL, &addr);
}

void runFailure1() {
    struct ether_addr addr;
    ether_aton_r(anystring(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct ether_addr addr;
    ether_aton_r(anystring(), &addr);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
