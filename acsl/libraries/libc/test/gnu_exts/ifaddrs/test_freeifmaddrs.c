#include "../../../test_common.h"
#include <ifaddrs.h>

void runSuccess() {
    struct ifmaddrs * ifa;
    if (!getifmaddrs(&ifa)) {
        freeifmaddrs(ifa);
    }
}

void runFailure() {
    freeifmaddrs(NULL);
}

void runFailure1() {
    struct ifmaddrs * ifa;
    if (!getifmaddrs(&ifa)) {
        freeifmaddrs(ifa);
        freeifmaddrs(ifa);
    }
}

int f;
void testValues() {
    f = 2;
    
    struct ifmaddrs * ifa;
    if (!getifmaddrs(&ifa)) {
        freeifmaddrs(ifa);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
