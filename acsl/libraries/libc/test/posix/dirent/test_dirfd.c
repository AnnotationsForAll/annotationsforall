#include "../../../test_common.h"
#include <dirent.h>
#include <errno.h>

void runSuccess() {
    DIR* dir = fdopendir(0);
    if (dir != NULL) {
        dirfd(dir);
    }
}

void runFailure() {
    dirfd(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    DIR* dir = fdopendir(0);
    if (dir != NULL) {
        dirfd(dir);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
