#include "../../../test_common.h"
#include <netinet/ether.h>

void runSuccess() {
    struct ether_addr addr;
    ether_ntoa(&addr);
}

void runFailure() {
    ether_ntoa(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct ether_addr addr;
    char* result = ether_ntoa(&addr);
    //@ assert valid_string(result);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
