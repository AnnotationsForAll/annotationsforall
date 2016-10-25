#include "../../../stdio_common.h"
#include <shadow.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file) {
        struct spwd p;
        struct spwd * pp;
        char buf[10];
        fgetspent_r(file, &p, buf, 10, &pp);
    }
}

void runFailure() {
    FILE* file = VALID_FILE;
    if (file) {
        struct spwd p;
        struct spwd * pp;
        char buf[10];
        fgetspent_r(file, NULL, buf, 10, &pp);
    }
}

void runFailure1() {
    FILE* file = VALID_FILE;
    if (file) {
        struct spwd p;
        struct spwd * pp;
        char buf[10];
        fgetspent_r(file, &p, NULL, 10, &pp);
    }
}

void runFailure2() {
    FILE* file = VALID_FILE;
    if (file) {
        struct spwd p;
        struct spwd * pp;
        char buf[10];
        fgetspent_r(file, &p, buf, 20, &pp);
    }
}

void runFailure3() {
    FILE* file = VALID_FILE;
    if (file) {
        struct spwd p;
        struct spwd * pp;
        char buf[10];
        fgetspent_r(file, &p, buf, 10, NULL);
    }
}

void runFailure4() {
    FILE* file = VALID_FILE;
    if (file) {
        struct spwd p;
        struct spwd * pp;
        char buf[10];
        fgetspent_r(NULL, &p, buf, 10, &pp);
    }
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file) {
        struct spwd p;
        struct spwd * pp;
        char buf[10];
        fgetspent_r(file, &p, buf, 10, &pp);
        //@ assert pp != \null ==> \valid_read(pp->sp_namp);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
