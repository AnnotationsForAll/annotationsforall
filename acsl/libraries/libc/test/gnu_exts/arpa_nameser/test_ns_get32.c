#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char buf[sizeof(u_long)];
    ns_get32(buf);
}

void runFailure() {
    ns_get32(NULL);
}

void runFailure1() {
    u_char buf[sizeof(u_long)-1];
    ns_get32(buf);
}

int f;
void testValues() {
    f = 2;
    
    u_char buf[sizeof(u_long)];
    ns_get32(buf);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
