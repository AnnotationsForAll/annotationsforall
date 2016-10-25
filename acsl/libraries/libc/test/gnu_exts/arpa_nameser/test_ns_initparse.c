#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char buf[10];
    ns_msg handle;
    ns_initparse(buf, 10, &handle);
}

void runSuccess1() {
    u_char buf[10];
    ns_msg handle;
    ns_initparse(buf, 5, &handle);
}

void runFailure() {
    u_char buf[10];
    ns_msg handle;
    ns_initparse(NULL, anyint(), &handle);
}

void runFailure1() {
    u_char buf[10];
    ns_msg handle;
    ns_initparse(buf, 10, NULL);
}

void runFailure2() {
    u_char buf[10];
    ns_msg handle;
    ns_initparse(buf, 20, &handle);
}

int f;
void testValues() {
    f = 2;
    
    u_char buf[10];
    ns_msg handle;
    ns_initparse(buf, 10, &handle);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
