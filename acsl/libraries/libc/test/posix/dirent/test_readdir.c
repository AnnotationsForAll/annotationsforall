#include "../../../test_common.h"
#include <dirent.h>
#include <errno.h>

void runSuccess() {
    DIR* dir = fdopendir(0);
    if (dir != NULL) {
        readdir(dir);
    }
}

void runFailure() {
    readdir(NULL);
}

int f;
void testValues() {
    f = 2;
    struct dirent * result;
    
    DIR* dir = fdopendir(0);
    if (dir != NULL) {
        result = readdir(dir);
        //@ assert result == \null || \valid(result);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
