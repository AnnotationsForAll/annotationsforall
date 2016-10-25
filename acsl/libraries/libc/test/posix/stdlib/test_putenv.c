#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    char buf[] = "a=b";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    putenv(buf);
}

void runFailure() {
    putenv(NULL);
}

//FIXME: POSIX doesn't say what happens when string given isn't of form "key=value". Is this undefined behavior?

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "a=b";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = putenv(buf);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
