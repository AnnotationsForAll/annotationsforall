#include "../../../stdio_common.h"
#include <malloc.h>

void runSuccess() {
    stderr = VALID_FILE;
    if (stderr) {
        malloc_stats();
    }
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    stderr = VALID_FILE;
    if (stderr) {
        malloc_stats();
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
