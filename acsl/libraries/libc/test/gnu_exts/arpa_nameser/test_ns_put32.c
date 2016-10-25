#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char buf[sizeof(u_long)];
    ns_put32(anyint(), buf);
}

void runFailure() {
    ns_put32(anyint(), NULL);
}

void runFailure1() {
    u_char buf[sizeof(u_long)-1];
    ns_put32(anyint(), buf);
}

int f;
void testValues() {
    f = 2;
    
    u_long i = anylong();
    u_char buf[sizeof(u_long)];
    ns_put32(i, buf);
    u_long result = ns_get32(buf);
    //@ assert i == result;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
