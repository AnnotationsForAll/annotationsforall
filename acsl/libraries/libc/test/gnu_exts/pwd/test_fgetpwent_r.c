#include "../../../stdio_common.h"
#include <pwd.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct passwd res;
        struct passwd * resp;
        char buf[10];
        fgetpwent_r(file, &res, buf, 10, &resp);
    }
}

void runFailure() {
    struct passwd res;
    struct passwd * resp;
    char buf[10];
    fgetpwent_r(NULL, &res, buf, 10, &resp);
}

void runFailure1() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct passwd res;
        struct passwd * resp;
        char buf[10];
        fgetpwent_r(file, NULL, buf, 10, &resp);
    }
}

void runFailure2() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct passwd res;
        struct passwd * resp;
        char buf[10];
        fgetpwent_r(file, &res, NULL, 10, &resp);
    }
}

void runFailure3() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct passwd res;
        struct passwd * resp;
        char buf[10];
        fgetpwent_r(file, &res, buf, 20, &resp);
    }
}

void runFailure4() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct passwd res;
        struct passwd * resp;
        char buf[10];
        fgetpwent_r(file, &res, buf, 10, NULL);
    }
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct passwd res;
        struct passwd * resp;
        char buf[10];
        fgetpwent_r(file, &res, buf, 10, &resp);
        //@ assert resp == \null || *resp == res;
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
