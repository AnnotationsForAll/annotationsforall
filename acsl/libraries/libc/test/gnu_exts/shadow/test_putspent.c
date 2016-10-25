#include "../../../stdio_common.h"
#include <shadow.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file) {
        struct spwd p;
        p.sp_namp = anystring();
        p.sp_pwdp = anystring();

        putspent(&p, file);
    }
}

void runFailure() {
    FILE* file = VALID_FILE;
    if (file) {
        struct spwd p;
        p.sp_namp = anystring();
        p.sp_pwdp = anystring();

        putspent(NULL, file);
    }
}

void runFailure1() {
    FILE* file = VALID_FILE;
    if (file) {
        struct spwd p;
        p.sp_namp = anystring();
        p.sp_pwdp = anystring();

        putspent(&p, NULL);
    }
}

void runFailure2() {
    FILE* file = VALID_FILE;
    if (file) {
        struct spwd p;
        p.sp_pwdp = anystring();

        putspent(&p, file);
    }
}

void runFailure3() {
    FILE* file = VALID_FILE;
    if (file) {
        struct spwd p;
        p.sp_namp = anystring();

        putspent(&p, file);
    }
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file) {
        struct spwd p;
        p.sp_namp = anystring();
        p.sp_pwdp = anystring();

        putspent(&p, file);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
