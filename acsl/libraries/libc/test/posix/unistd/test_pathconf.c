#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    pathconf(buf, anyint());
}

void runFailure() {
    pathconf(NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    long int result;
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    pathconf(buf, anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
