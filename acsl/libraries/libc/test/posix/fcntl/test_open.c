#include "../../../test_common.h"
#include <fcntl.h>

void runSuccess() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    open(buf, O_RDWR);
}

void runFailure() {
    open(NULL, O_RDWR);
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    open(buf, O_RDWR);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
