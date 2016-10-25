#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    char buf[PATH_MAX];
    getwd(buf);
}

void runFailure() {
    getwd(NULL);
}

void runFailure1() {
    char buf[PATH_MAX - 1];
    getwd(buf);
}

int f;
void testValues() {
    f = 2;
    
    char buf[PATH_MAX];
    char* result = getwd(buf);
    //@ assert result == buf || result == \null;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
