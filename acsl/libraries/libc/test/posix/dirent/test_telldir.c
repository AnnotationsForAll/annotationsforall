#include "../../../test_common.h"
#include <dirent.h>
#include <errno.h>

void runSuccess() {
    DIR* dir = fdopendir(0);
    if (dir != NULL) {
        telldir(dir);
    }
}

void runFailure() {
    telldir(NULL);
}

int f;
void testValues() {
    f = 2;
    long int result;
    
    DIR* dir = fdopendir(0);
    if (dir != NULL) {
        result = telldir(dir);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
