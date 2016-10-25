#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char buf[sizeof(u_int)];
    ns_get16(buf);
}

void runFailure() {
    ns_get16(NULL);
}

void runFailure1() {
    u_char buf[sizeof(u_int)-1];
    ns_get16(buf);
}

int f;
void testValues() {
    f = 2;
    
    u_char buf[sizeof(u_int)];
    ns_get16(buf);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
