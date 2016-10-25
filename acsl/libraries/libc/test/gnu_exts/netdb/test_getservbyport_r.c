#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservbyport_r(anyint(), anystring(), &result, buf, 10, &rp);
}

void runFailure() {
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservbyport_r(anyint(), anystring(), NULL, buf, 10, &rp);
}

void runFailure1() {
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservbyport_r(anyint(), anystring(), &result, NULL, 10, &rp);
}

void runFailure2() {
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservbyport_r(anyint(), anystring(), &result, buf, 20, &rp);
}

void runFailure3() {
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservbyport_r(anyint(), anystring(), &result, buf, 10, NULL);
}

void runFailure4() {
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservbyport_r(anyint(), NULL, &result, buf, 10, &rp);
}

int f;
void testValues() {
    f = 2;
    
    struct servent result;
    struct servent * rp;
    char buf[10];
    getservbyport_r(anyint(), anystring(), &result, buf, 10, &rp);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
