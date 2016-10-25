#include "../../../stdio_common.h"
#include <argp.h>

void runSuccess() {
    struct argp_state argp;
    FILE* file = VALID_FILE;
    if (file != NULL) {
        argp.err_stream = file;
        argp_failure(&argp, anyint(), anyint(), anystring());
    }
}

void runFailure() {
    argp_failure(NULL, anyint(), anyint(), anystring());
}

void runFailure1() {
    struct argp_state argp;
    argp.err_stream = NULL;
    argp_failure(&argp, anyint(), anyint(), anystring());
}

void runFailure2() {
    struct argp_state argp;
    argp.err_stream = NULL;
    argp_failure(&argp, anyint(), anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct argp_state argp;
    FILE* file = VALID_FILE;
    if (file != NULL) {
        argp.err_stream = file;
        argp_failure(&argp, 0, anyint(), anystring());
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
