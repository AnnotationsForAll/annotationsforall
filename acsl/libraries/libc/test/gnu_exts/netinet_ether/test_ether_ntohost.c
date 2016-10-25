#include "../../../test_common.h"
#include <netinet/ether.h>

void runSuccess() {
    char buf[255];
    struct ether_addr addr;
    ether_ntohost(buf, &addr);
}

void runFailure() {
    char buf[255];
    struct ether_addr addr;
    ether_ntohost(NULL, &addr);
}

void runFailure1() {
    char buf[255];
    struct ether_addr addr;
    ether_ntohost(buf, NULL);
}

void runFailure2() {
    char buf[254];
    struct ether_addr addr;
    ether_ntohost(buf, &addr);
}

int f;
void testValues() {
    f = 2;
    
    char buf[255];
    struct ether_addr addr;
    ether_ntohost(buf, &addr);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
