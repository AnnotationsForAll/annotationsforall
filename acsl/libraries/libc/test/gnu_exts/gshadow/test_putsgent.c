#include "../../../stdio_common.h"
#include <gshadow.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct sgrp p;
        putsgent(&p, file);
    }
}

void runFailure() {
    struct sgrp p;
    putsgent(&p, NULL);
}

void runFailure1() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct sgrp p;
        putsgent(NULL, file);
    }
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct sgrp p;
        putsgent(&p, file);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
