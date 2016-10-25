#include "../../../test_common.h"
#include <fcntl.h>

void runSuccess() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    openat(anyint(), buf, O_RDWR);
}

void runFailure() {
    openat(anyint(), NULL, O_RDWR);
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    openat(anyint(), buf, O_RDWR);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
