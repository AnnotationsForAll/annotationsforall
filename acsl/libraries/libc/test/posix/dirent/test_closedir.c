#include "../../../test_common.h"
#include <dirent.h>
#include <errno.h>

void runSuccess() {
    DIR* dir = fdopendir(0);
    if (dir != NULL) {
        closedir(dir);
    }
}

void runFailure() {
    closedir(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    DIR* p = anydir();
    
    DIR* dir = fdopendir(0);
    if (dir != NULL) {
        result = closedir(dir);
        //@ assert result != -1 ==> !\valid(p);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
