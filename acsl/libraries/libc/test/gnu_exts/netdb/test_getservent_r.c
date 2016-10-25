#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservent_r(&result, buf, 10, &rp);
}

void runFailure() {
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservent_r(NULL, buf, 10, &rp);
}

void runFailure1() {
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservent_r(&result, NULL, 10, &rp);
}

void runFailure2() {
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservent_r(&result, buf, 20, &rp);
}

void runFailure3() {
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservent_r(&result, buf, 10, NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservent_r(&result, buf, 10, &rp);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
