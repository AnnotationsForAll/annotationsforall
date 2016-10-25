#include "../../../test_common.h"
#include <netinet/ether.h>

void runSuccess() {
    ether_aton(anystring());
}

void runFailure() {
    ether_aton(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct ether_addr* result = ether_aton(anystring());
    //@ assert \valid(result);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
