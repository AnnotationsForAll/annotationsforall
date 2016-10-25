#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    struct protoent result;
    struct protoent * rp;
    char buf[10];
    getprotobyname_r(anystring(), &result, buf, 10, &rp);
}

void runFailure() {
    struct protoent result;
    struct protoent * rp;
    char buf[10];
    getprotobyname_r(anystring(), NULL, buf, 10, &rp);
}

void runFailure1() {
    struct protoent result;
    struct protoent * rp;
    char buf[10];
    getprotobyname_r(anystring(), &result, NULL, 10, &rp);
}

void runFailure2() {
    struct protoent result;
    struct protoent * rp;
    char buf[10];
    getprotobyname_r(anystring(), &result, buf, 20, &rp);
}

void runFailure3() {
    struct protoent result;
    struct protoent * rp;
    char buf[10];
    getprotobyname_r(anystring(), &result, buf, 10, NULL);
}

void runFailure5() {
    struct protoent result;
    struct protoent * rp;
    char buf[10];
    getprotobyname_r(NULL, &result, buf, 10, &rp);
}

int f;
void testValues() {
    f = 2;
    
    struct protoent result;
    struct protoent * rp;
    char buf[10];
    getprotobyname_r(anystring(), &result, buf, 10, &rp);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
