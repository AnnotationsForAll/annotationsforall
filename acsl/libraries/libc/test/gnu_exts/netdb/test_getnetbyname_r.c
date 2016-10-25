#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    struct netent result;
    struct netent * rp;
    char buf[10];
    int err;
    getnetbyname_r(anystring(), &result, buf, 10, &rp, &err);
}

void runFailure() {
    struct netent result;
    struct netent * rp;
    char buf[10];
    int err;
    getnetbyname_r(anystring(), NULL, buf, 10, &rp, &err);
}

void runFailure1() {
    struct netent result;
    struct netent * rp;
    char buf[10];
    int err;
    getnetbyname_r(anystring(), &result, NULL, 10, &rp, &err);
}

void runFailure2() {
    struct netent result;
    struct netent * rp;
    char buf[10];
    int err;
    getnetbyname_r(anystring(), &result, buf, 20, &rp, &err);
}

void runFailure3() {
    struct netent result;
    struct netent * rp;
    char buf[10];
    int err;
    getnetbyname_r(anystring(), &result, buf, 10, NULL, &err);
}

void runFailure4() {
    struct netent result;
    struct netent * rp;
    char buf[10];
    int err;
    getnetbyname_r(anystring(), &result, buf, 10, &rp, NULL);
}

void runFailure5() {
    struct netent result;
    struct netent * rp;
    char buf[10];
    int err;
    getnetbyname_r(NULL, &result, buf, 10, &rp, &err);
}

int f;
void testValues() {
    f = 2;
    
    struct netent result;
    struct netent * rp;
    char buf[10];
    int err;
    getnetbyname_r(anystring(), &result, buf, 10, &rp, &err);
    //@ assert err == 0 ==> \valid(rp);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
