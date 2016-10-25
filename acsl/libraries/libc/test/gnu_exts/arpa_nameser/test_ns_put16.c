#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char buf[sizeof(u_int)];
    ns_put16(anyint(), buf);
}

void runFailure() {
    ns_put16(anyint(), NULL);
}

void runFailure1() {
    u_char buf[sizeof(u_int)-1];
    ns_put16(anyint(), buf);
}

int f;
void testValues() {
    f = 2;
    
    u_int i = anyint();
    u_char buf[sizeof(u_int)];
    ns_put16(i, buf);
    u_int result = ns_get16(buf);
    //@ assert i == result;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
