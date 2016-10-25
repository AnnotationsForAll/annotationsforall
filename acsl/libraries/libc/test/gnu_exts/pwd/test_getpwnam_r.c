#include "../../../stdio_common.h"
#include <pwd.h>

void runSuccess() {
    struct passwd res;
    struct passwd * resp;
    char buf[10];
    getpwnam_r(anystring(), &res, buf, 10, &resp);
}

void runFailure() {
    struct passwd res;
    struct passwd * resp;
    char buf[10];
    getpwnam_r(anystring(), NULL, buf, 10, &resp);
}

void runFailure1() {
    struct passwd res;
    struct passwd * resp;
    char buf[10];
    getpwnam_r(anystring(), &res, NULL, 10, &resp);
}

void runFailure2() {
    struct passwd res;
    struct passwd * resp;
    char buf[10];
    getpwnam_r(anystring(), &res, buf, 20, &resp);
}

void runFailure3() {
    struct passwd res;
    struct passwd * resp;
    char buf[10];
    getpwnam_r(anystring(), &res, buf, 10, NULL);
}

void runFailure4() {
    struct passwd res;
    struct passwd * resp;
    char buf[10];
    getpwnam_r(NULL, &res, buf, 10, &resp);
}

int f;
void testValues() {
    f = 2;
    
    struct passwd res;
    struct passwd * resp;
    char buf[10];
    getpwnam_r(anystring(), &res, buf, 10, &resp);
    //@ assert resp == \null || *resp == res;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
