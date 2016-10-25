#include "../../../stdio_common.h"
#include <stdio.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        setlinebuf(file);
    }
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        setlinebuf(file);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
