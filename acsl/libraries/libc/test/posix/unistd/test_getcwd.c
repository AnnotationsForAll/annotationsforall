#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    char buf[10];
    getcwd(buf, 10);
}

void runFailure() {
    getcwd(NULL, 10);
}

void runFailure1() {
    char buf[10];
    getcwd(buf, 20);
}

int f;
void testValues() {
    f = 2;
    char* result;
    char buf[10];
    
    result = getcwd(buf, 10);
    //@ assert result == \null || result == buf;
    //@ assert result != \null ==> \valid_read(buf);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
