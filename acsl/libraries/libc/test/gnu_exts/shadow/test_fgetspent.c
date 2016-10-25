#include "../../../stdio_common.h"
#include <shadow.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file) {
        fgetspent(file);
    }
}

void runFailure() {
    fgetspent(NULL);
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file) {
        struct spwd * result = fgetspent(file);
        //@ assert result != \null ==> \valid_read(result->sp_namp);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
