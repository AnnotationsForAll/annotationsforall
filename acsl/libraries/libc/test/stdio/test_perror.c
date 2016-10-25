#include "../../stdio_common.h"

void runSuccess() {
    char buf[] = "ERR";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    perror(buf);
}

void runFailure() {
}

int f;
void testValues() {
    f = 2;
    char buf[] = "ERR";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    perror(buf);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
