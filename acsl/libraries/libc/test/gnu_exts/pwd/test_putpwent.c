#include "../../../stdio_common.h"
#include <pwd.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct passwd p;
        putpwent(&p, file);
    }
}

void runFailure() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        putpwent(NULL, file);
    }
}

void runFailure1() {
    struct passwd p;
    putpwent(&p, NULL);
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct passwd p;
        putpwent(&p, file);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
