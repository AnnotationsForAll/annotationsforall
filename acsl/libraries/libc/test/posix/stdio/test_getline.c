#include "../../../stdio_common.h"

void runSuccess() {
    size_t len = 4;
    char buf[4];
    char* bufp = buf;
    
    if (buf != NULL) {
        FILE* file = VALID_FILE;
        if (file != NULL) {
            getline(&bufp, &len, file);
        }
    }
}

void runFailure() {
    size_t len = anysize();
    FILE* file = VALID_FILE;
    if (file != NULL) {
        getline(NULL, &len, file);
    }
}

void runFailure1() {
    size_t len = anysize();
    char* buf = malloc(len);
    
    if (buf != NULL) {
        FILE* file = VALID_FILE;
        if (file != NULL) {
            getline(&buf, NULL, file);
        }
    }
}

void runFailure2() {
    size_t len = anysize();
    char* buf = malloc(len);
    
    if (buf != NULL) {
        getline(&buf, &len, NULL);
    }
}

int f;
void testValues() {
    f = 2;
    ssize_t result;
    size_t len = anysize();
    char* buf = malloc(len);
    
    if (buf != NULL) {
        FILE* file = VALID_FILE;
        if (file != NULL) {
            result = getline(&buf, &len, file);
            //@ assert result >= -1;
        }
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
