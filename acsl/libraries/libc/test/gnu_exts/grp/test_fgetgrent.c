#include "../../../stdio_common.h"
#include <grp.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fgetgrent(file);
    }
}

void runFailure() {
    fgetgrent(NULL);
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct group * result = fgetgrent(file);
        //@ assert result == \null || \valid(result);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
