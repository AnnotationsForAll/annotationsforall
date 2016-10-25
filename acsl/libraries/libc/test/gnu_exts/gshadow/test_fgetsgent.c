#include "../../../stdio_common.h"
#include <gshadow.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fgetsgent(file);
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
        struct group * result = fgetsgent(file);
        //@ assert result == \null || \valid(result);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
