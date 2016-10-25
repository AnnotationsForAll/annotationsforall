#include "../../../test_common.h"
#include <netinet/ether.h>

void runSuccess() {
    struct ether_addr addr;
    char buf[16];
    ether_ntoa_r(&addr, buf);
}

void runFailure() {
    struct ether_addr addr;
    char buf[16];
    ether_ntoa_r(NULL, buf);
}

void runFailure1() {
    struct ether_addr addr;
    char buf[16];
    ether_ntoa_r(&addr, NULL);
}

void runFailure2() {
    struct ether_addr addr;
    char buf[15];
    ether_ntoa_r(&addr, buf);
}

int f;
void testValues() {
    f = 2;
    
    struct ether_addr addr;
    char buf[16];
    ether_ntoa_r(&addr, buf);
    //@ assert valid_string((char*)buf);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
