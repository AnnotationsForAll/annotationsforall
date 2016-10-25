#include "../../stdio_common.h"

void runSuccess() {
    char buf[] = "file";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    remove(buf);
}

void runFailure() {
    remove(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "file";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = remove(buf);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
