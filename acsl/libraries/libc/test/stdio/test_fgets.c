#include "../../stdio_common.h"

void runSuccess() {
    char buf[10];
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fgets(buf, 10, file);
    }
}

void runSuccess1() {
    char buf[10];
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fgets(buf, 5, file);
    }
}

void runFailure() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fgets(NULL, 5, file);
    }
}

void runFailure1() {
    char buf[10];
    
    fgets(buf, 10, NULL);
}

void runFailure2() {
    char buf[10];
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fgets(buf, 20, file);
    }
}

int f;
void testValues() {
    f = 2;
    char* result;
    char buf[10];
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = fgets(buf, 10, file);
        //@ assert result == \null || result == buf;
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
