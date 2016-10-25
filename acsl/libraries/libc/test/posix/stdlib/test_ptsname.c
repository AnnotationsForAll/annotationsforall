#include "../../../unistd_common.h"
#include <stdlib.h>

void runSuccess() {
    int fd = VALID_FD;
    if (fd != -1) {
        ptsname(fd);
    }
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    int fd = VALID_FD;
    if (fd != -1) {
        result = ptsname(fd);
        //@ assert result == \null || \valid(result);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
