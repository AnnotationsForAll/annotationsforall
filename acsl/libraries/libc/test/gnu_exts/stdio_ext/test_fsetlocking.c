#include "../../../stdio_common.h"
#include <stdio_ext.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        __fsetlocking(file, FSETLOCKING_INTERNAL);
    }
}

void runSuccess1() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        __fsetlocking(file, FSETLOCKING_BYCALLER);
    }
}

void runSuccess2() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        __fsetlocking(file, FSETLOCKING_QUERY);
    }
}

void runFailure() {
    __fsetlocking(NULL, FSETLOCKING_QUERY);
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        int result = __fsetlocking(file, FSETLOCKING_QUERY);
        //@ assert result == FSETLOCKING_INTERNAL || result == FSETLOCKING_BYCALLER;
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
