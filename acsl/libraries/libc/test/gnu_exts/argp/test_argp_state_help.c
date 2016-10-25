#include "../../../stdio_common.h"
#include <argp.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    struct argp_state argp;
    if (file != NULL) {
        argp_state_help(&argp, file, anyint());
    }
}

void runFailure() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        argp_state_help(NULL, file, anyint());
    }
}

void runFailure1() {
    struct argp_state argp;
    argp_state_help(&argp, NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    struct argp_state argp;
    if (file != NULL) {
        argp_state_help(&argp, file, anyint());
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
