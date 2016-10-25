#include "../../stdio_common.h"

void runSuccess() {
    char buf[] = "%s";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    printf(buf, "Hello");
}

void runFailure() {
    printf(NULL, "Hello");
}

int f;
void testValues() {
    f = 2;
    int result;
    
    char buf[] = "%s";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = printf(buf, "Hello");
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
