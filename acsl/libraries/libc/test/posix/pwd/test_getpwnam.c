#include "../../../test_common.h"
#include <pwd.h>

void runSuccess() {
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    getpwnam(buf);
}

void runFailure() {
    getpwnam(NULL);
}

int f;
void testValues() {
    f = 2;
    struct passwd * result;
    
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = getpwnam(buf);
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
