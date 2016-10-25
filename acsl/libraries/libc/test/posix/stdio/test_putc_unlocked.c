#include "../../../stdio_common.h"

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        putc_unlocked(anyint(), file);
    }
}

void runFailure() {
    putc_unlocked(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = putc_unlocked(anyint(), file);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
