#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    struct protoent result;
    struct protoent * rp;
    char buf[10];
    getprotobynumber_r(anyint(), &result, buf, 10, &rp);
}

void runFailure() {
    struct protoent result;
    struct protoent * rp;
    char buf[10];
    getprotobynumber_r(anyint(), NULL, buf, 10, &rp);
}

void runFailure1() {
    struct protoent result;
    struct protoent * rp;
    char buf[10];
    getprotobynumber_r(anyint(), &result, NULL, 10, &rp);
}

void runFailure2() {
    struct protoent result;
    struct protoent * rp;
    char buf[10];
    getprotobynumber_r(anyint(), &result, buf, 20, &rp);
}

void runFailure3() {
    struct protoent result;
    struct protoent * rp;
    char buf[10];
    getprotobynumber_r(anyint(), &result, buf, 10, NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct protoent result;
    struct protoent * rp;
    char buf[10];
    getprotobynumber_r(anyint(), &result, buf, 10, &rp);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
