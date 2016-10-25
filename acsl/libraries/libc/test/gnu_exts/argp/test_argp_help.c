#include "../../../stdio_common.h"
#include <argp.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    struct argp argp;
    if (file != NULL) {
        argp_help(&argp, file, anyint(), anystring());
    }
}

void runFailure() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        argp_help(NULL, file, anyint(), anystring());
    }
}

void runFailure1() {
    struct argp argp;
    argp_help(&argp, NULL, anyint(), anystring());
}

void runFailure2() {
    FILE* file = VALID_FILE;
    struct argp argp;
    if (file != NULL) {
        argp_help(&argp, file, anyint(), NULL);
    }
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    struct argp argp;
    if (file != NULL) {
        argp_help(&argp, file, anyint(), anystring());
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
