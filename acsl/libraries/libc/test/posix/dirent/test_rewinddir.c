#include "../../../test_common.h"
#include <dirent.h>
#include <errno.h>

void runSuccess() {
    DIR* dir = fdopendir(0);
    if (dir != NULL) {
        rewinddir(dir);
    }
}

void runFailure() {
    rewinddir(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    DIR* dir = fdopendir(0);
    if (dir != NULL) {
        rewinddir(dir);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
