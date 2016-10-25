#include "../../../unistd_common.h"
#include <stdlib.h>

void runSuccess() {
    int fd = VALID_FD;
    if (fd != -1) {
        unlockpt(fd);
    }
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    int fd = VALID_FD;
    if (fd != -1) {
        result = unlockpt(fd);
        //@ assert result == 0 || result == -1;
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
