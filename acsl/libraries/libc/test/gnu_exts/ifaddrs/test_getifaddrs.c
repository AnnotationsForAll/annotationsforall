#include "../../../test_common.h"
#include <ifaddrs.h>

void runSuccess() {
    struct ifaddrs * ifa;
    getifaddrs(&ifa);
}

void runFailure() {
    getifaddrs(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct ifaddrs * ifa;
    int result = getifaddrs(&ifa);
    //@ assert result == 0 ==> \valid(ifa);
    if (!result) {
        //@ assert (ifa->ifa_addr == \null || \valid(ifa->ifa_addr));
        if (ifa->ifa_next) {
            //@ assert ifa->ifa_next->ifa_addr == \null || \valid(ifa->ifa_next->ifa_addr);
        }
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
