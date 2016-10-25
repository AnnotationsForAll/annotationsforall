#include "../../stdio_common.h"

void runSuccess() {
    char buf[100];
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fread(buf, 1, 100, file);
    }
}

void runSuccess1() {
    char buf[100];
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fread(buf, 1, 50, file);
    }
}

void runSuccess2() {
    char buf[100];
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fread(buf, 2, 50, file);
    }
}

void runFailure() {
    char buf[100];
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fread(NULL, 1, 100, file);
    }
}

void runFailure1() {
    char buf[100];
    
    fread(buf, 1, 100, NULL);
}

void runFailure2() {
    char buf[100];
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fread(NULL, 1, 200, file);
    }
}

void runFailure3() {
    char buf[100];
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fread(NULL, 2, 100, file);
    }
}

int f;
void testValues() {
    f = 2;
    size_t result;
    char buf[100];
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = fread(buf, 1, 100, file);
        //@ assert result <= 100;
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
