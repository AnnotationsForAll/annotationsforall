#include "../../../stdio_common.h"
#include <stdio.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        setbuffer(file, NULL, 0);
    }
}

void runSuccess1() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        char buf[10];
        setbuffer(file, buf, 10);
    }
}

void runFailure() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        char buf[10];
        setbuffer(file, buf, 20);
    }
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        setbuffer(file, NULL, 0);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
