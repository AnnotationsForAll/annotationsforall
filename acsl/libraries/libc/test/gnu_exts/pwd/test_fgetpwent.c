#include "../../../stdio_common.h"
#include <pwd.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fgetpwent(file);
    }
}

void runFailure() {
    fgetpwent(NULL);
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct group * result = fgetpwent(file);
        //@ assert result == \null || \valid(result);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
