#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservbyname_r(anystring(), anystring(), &result, buf, 10, &rp);
}

void runFailure() {
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservbyname_r(anystring(), anystring(), NULL, buf, 10, &rp);
}

void runFailure1() {
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservbyname_r(anystring(), anystring(), &result, NULL, 10, &rp);
}

void runFailure2() {
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservbyname_r(anystring(), anystring(), &result, buf, 20, &rp);
}

void runFailure3() {
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservbyname_r(anystring(), anystring(), &result, buf, 10, NULL);
}

void runFailure5() {
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservbyname_r(NULL, anystring(), &result, buf, 10, &rp);
}

void runFailure4() {
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservbyname_r(anystring(), NULL, &result, buf, 10, &rp);
}

int f;
void testValues() {
    f = 2;
    
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservbyname_r(anystring(), anystring(), &result, buf, 10, &rp);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
