#include "../../stdio_common.h"

void runSuccess() {
    char buf[] = "Hi";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    puts(buf);
}

void runFailure() {
    puts(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "Hi";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = puts(buf);
    //@ assert result == EOF || result >= 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
