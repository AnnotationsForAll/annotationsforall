#include "../../../test_common.h"
#include <ifaddrs.h>

void runSuccess() {
    struct ifmaddrs * ifa;
    getifmaddrs(&ifa);
}

void runFailure() {
    getifmaddrs(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct ifmaddrs * ifa;
    int result = getifmaddrs(&ifa);
    //@ assert result == 0 ==> \valid(ifa);
    if (!result) {
        //@ assert (ifa->ifma_addr == \null || \valid(ifa->ifma_addr));
        if (ifa->ifma_next) {
            //@ assert ifa->ifma_next->ifma_addr == \null || \valid(ifa->ifma_next->ifma_addr);
        }
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
