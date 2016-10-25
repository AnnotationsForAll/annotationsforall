#include "../../../test_common.h"
#include <shadow.h>

void runSuccess() {
    struct spwd p;
    struct spwd * pp;
    char buf[10];
    getspent_r(&p, buf, 10, &pp);
}

void runFailure() {
    struct spwd p;
    struct spwd * pp;
    char buf[10];
    getspent_r(NULL, buf, 10, &pp);
}

void runFailure1() {
    struct spwd p;
    struct spwd * pp;
    char buf[10];
    getspent_r(&p, NULL, 10, &pp);
}

void runFailure2() {
    struct spwd p;
    struct spwd * pp;
    char buf[10];
    getspent_r(&p, buf, 30, &pp);
}

void runFailure3() {
    struct spwd p;
    struct spwd * pp;
    char buf[10];
    getspent_r(&p, buf, 10, NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct spwd p;
    struct spwd * pp;
    char buf[10];
    getspent_r(&p, buf, 10, &pp);
    //@ assert pp != \null ==> \valid_read(pp->sp_namp);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
