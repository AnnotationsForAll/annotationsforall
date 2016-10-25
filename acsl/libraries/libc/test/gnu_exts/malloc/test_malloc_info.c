#include "../../../stdio_common.h"
#include <malloc.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file) {
        malloc_info(0, file);
    }
}

void runSuccess1() {
    FILE* file = VALID_FILE;
    if (file) {
        malloc_info(anyint(), file);
    }
}

void runFailure() {
    malloc_info(0, NULL);
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file) {
        malloc_info(0, file);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
