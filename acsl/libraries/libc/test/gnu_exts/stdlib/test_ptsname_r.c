#include "../../../unistd_common.h"
#include <stdlib.h>

void runSuccess() {
    char buf[] = "s";
    int fd = VALID_FD;
    if (fd != -1) {
        ptsname_r(fd, buf, 1);
    }
}

void runFailure() {
    int fd = VALID_FD;
    if (fd != -1) {
        ptsname_r(fd, NULL, anysize());
    }
}

void runFailure1() {
    char buf[] = "s";
    int fd = VALID_FD;
    if (fd != -1) {
        ptsname_r(fd, buf, 30);
    }
}

int f;
void testValues() {
    f = 2;
    
    char buf[] = "s";
    int fd = VALID_FD;
    if (fd != -1) {
        ptsname_r(fd, buf, 1);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
