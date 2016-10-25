#include "../../stdio_common.h"

void runSuccess() {
    char buf[BUFSIZ];
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        setbuf(file, buf);
    }
}

void runSuccess1() {
    char buf[BUFSIZ];
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        setbuf(file, NULL);
    }
}

void runFailure() {
    char buf[BUFSIZ];
    
    setbuf(NULL, buf);
}

int f;
void testValues() {
    f = 2;
    char buf[BUFSIZ];
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        setbuf(file, buf);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
