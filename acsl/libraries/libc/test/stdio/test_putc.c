#include "../../stdio_common.h"

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        putc(anyint(), file);
    }
}

void runFailure() {
    putc(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = putc(anyint(), file);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
