#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    int fildes[2];
    fildes[0] = anyint();
    fildes[1] = anyint();
    
    pipe(fildes);
}

void runFailure() {
    pipe(NULL);
}

void runFailure1() {
    int fildes[1];
    fildes[0] = anyint();
    
    pipe(fildes);
}

int f;
void testValues() {
    f = 2;
    int result;
    int fildes[2];
    fildes[0] = anyint();
    fildes[1] = anyint();
    
    result = pipe(fildes);
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
