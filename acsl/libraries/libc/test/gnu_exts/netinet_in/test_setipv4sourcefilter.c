#include "../../../test_common.h"
#include <netinet/in.h>

void runSuccess() {
    struct in_addr addr;
    uint32_t mode;
    struct in_addr buf[] = {
            addr,
            addr,
            addr
    };
    uint32_t len = 3;
    setipv4sourcefilter(anyint(), addr, addr, mode, len, buf);
}

void runFailure() {
    struct in_addr addr;
    uint32_t mode;
    struct in_addr buf[] = {
            addr,
            addr,
            addr
    };
    uint32_t len = 3;
    setipv4sourcefilter(anyint(), addr, addr, mode, len, NULL);
}

void runFailure1() {
    struct in_addr addr;
    uint32_t mode;
    struct in_addr buf[] = {
            addr,
            addr,
            addr
    };
    uint32_t len = 10;
    setipv4sourcefilter(anyint(), addr, addr, mode, len, buf);
}

int f;
void testValues() {
    f = 2;
    
    struct in_addr addr;
    uint32_t mode;
    struct in_addr buf[] = {
            addr,
            addr,
            addr
    };
    uint32_t len = 3;
    setipv4sourcefilter(anyint(), addr, addr, mode, len, buf);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
