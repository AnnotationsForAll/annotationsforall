#include "../../../stdio_common.h"
#include <argp.h>

void runSuccess() {
    struct argp_state argp;
    FILE* file = VALID_FILE;
    if (file != NULL) {
        argp.err_stream = file;
        argp_usage(&argp);
    }
}

void runFailure() {
    argp_usage(NULL);
}

void runFailure1() {
    struct argp_state argp;
    argp.err_stream = NULL;
    argp_usage(&argp);
}

int f;
void testValues() {
    f = 2;
    
    struct argp_state argp;
    FILE* file = VALID_FILE;
    if (file != NULL) {
        argp.err_stream = file;
        argp_usage(&argp);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
