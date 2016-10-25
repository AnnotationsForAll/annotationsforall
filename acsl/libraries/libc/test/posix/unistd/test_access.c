#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    access(buf, anyint());
}

void runFailure() {
    access(NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = access(buf, anyint());
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
