#include "../../../test_common.h"
#include <netinet/ether.h>

void runSuccess() {
    char buf[255];
    struct ether_addr addr;
    ether_line(anystring(), &addr, buf);
}

void runFailure() {
    char buf[255];
    struct ether_addr addr;
    ether_line(NULL, &addr, buf);
}

void runFailure1() {
    char buf[255];
    struct ether_addr addr;
    ether_line(anystring(), NULL, buf);
}

void runFailure2() {
    char buf[254];
    struct ether_addr addr;
    ether_line(anystring(), &addr, buf);
}

void runFailure3() {
    char buf[255];
    struct ether_addr addr;
    ether_line(anystring(), &addr, NULL);
}

int f;
void testValues() {
    f = 2;
    
    char buf[255];
    struct ether_addr addr;
    ether_line(anystring(), &addr, buf);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
