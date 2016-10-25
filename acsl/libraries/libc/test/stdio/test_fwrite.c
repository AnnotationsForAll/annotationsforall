#include "../../stdio_common.h"

char buf[100];

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fwrite(buf, 1, 100, file);
    }
}

void runSuccess1() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fwrite(buf, 1, 50, file);
    }
}

void runSuccess2() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fwrite(buf, 2, 50, file);
    }
}

void runFailure() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fwrite(NULL, 1, 100, file);
    }
}

void runFailure1() {
    fwrite(buf, 1, 100, NULL);
}

void runFailure2() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fwrite(buf, 1, 200, file);
    }
}

void runFailure3() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fwrite(buf, 2, 100, file);
    }
}

int f;
void testValues() {
    f = 2;
    size_t result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = fwrite(buf, 1, 100, file);
        //@ assert result <= 100;
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
