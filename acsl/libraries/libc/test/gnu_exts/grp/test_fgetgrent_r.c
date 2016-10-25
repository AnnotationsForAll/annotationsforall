#include "../../../stdio_common.h"
#include <grp.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct group sg;
        char buf[10];
        struct group * p;
        fgetgrent_r(file, &sg, buf, 10, &p);
    }
}

void runFailure() {
    struct group sg;
    char buf[10];
    struct group * p;
    fgetgrent_r(NULL, &sg, buf, 10, &p);
}

void runFailure1() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct group sg;
        char buf[10];
        struct group * p;
        fgetgrent_r(file, NULL, buf, 10, &p);
    }
}

void runFailure2() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct group sg;
        char buf[10];
        struct group * p;
        fgetgrent_r(file, &sg, NULL, anysize(), &p);
    }
}

void runFailure3() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct group sg;
        char buf[10];
        struct group * p;
        fgetgrent_r(file, &sg, buf, 10, NULL);
    }
}

void runFailure4() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct group sg;
        char buf[10];
        struct group * p;
        fgetgrent_r(file, &sg, buf, 20, &p);
    }
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct group sg;
        char buf[10];
        struct group * p;
        fgetgrent_r(file, &sg, buf, 10, &p);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
