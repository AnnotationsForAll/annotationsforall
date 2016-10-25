#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    gid_t buf[10];
    getgroups(10, buf);
}

void runFailure() {
    getgroups(10, NULL);
}

void runFailure1() {
    gid_t buf[10];
    getgroups(20, buf);
}

int f;
void testValues() {
    f = 2;
    int result;
    gid_t buf[10];
    
    result = getgroups(10, buf);
    //@ assert result >= -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
