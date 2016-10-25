#include "../../../test_common.h"
#include <ifaddrs.h>

void runSuccess() {
    struct ifaddrs * ifa;
    if (!getifaddrs(&ifa)) {
        freeifaddrs(ifa);
    }
}

void runFailure() {
    freeifaddrs(NULL);
}

void runFailure1() {
    struct ifaddrs * ifa;
    if (!getifaddrs(&ifa)) {
        freeifaddrs(ifa);
        freeifaddrs(ifa);
    }
}

int f;
void testValues() {
    f = 2;
    
    struct ifaddrs * ifa;
    if (!getifaddrs(&ifa)) {
        freeifaddrs(ifa);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
