#include "../../../stdio_common.h"
#include <wchar.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fwide(file, 0);
    }
}

void runSuccess1() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fwide(file, 7);
    }
}

void runSuccess2() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fwide(file, -2);
    }
}

void runSuccess3() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fwide(file, anyint());
    }
}

void runFailure() {
    fwide(NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fwide(file, 0);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
