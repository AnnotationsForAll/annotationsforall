#include "../../../test_common.h"
#include <shadow.h>

void runSuccess() {
    struct spwd p;
    struct spwd * pp;
    char buf[10];
    getspnam_r(anystring(), &p, buf, 10, &pp);
}

void runFailure() {
    struct spwd p;
    struct spwd * pp;
    char buf[10];
    getspnam_r(anystring(), NULL, buf, 10, &pp);
}

void runFailure1() {
    struct spwd p;
    struct spwd * pp;
    char buf[10];
    getspnam_r(anystring(), &p, NULL, 10, &pp);
}

void runFailure2() {
    struct spwd p;
    struct spwd * pp;
    char buf[10];
    getspnam_r(anystring(), &p, buf, 30, &pp);
}

void runFailure3() {
    struct spwd p;
    struct spwd * pp;
    char buf[10];
    getspnam_r(anystring(), &p, buf, 10, NULL);
}

void runFailure4() {
    struct spwd p;
    struct spwd * pp;
    char buf[10];
    getspnam_r(NULL, &p, buf, 10, NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct spwd p;
    struct spwd * pp;
    char buf[10];
    getspnam_r(anystring(), &p, buf, 10, &pp);
    //@ assert pp != \null ==> \valid_read(pp->sp_namp);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
