#include "../../stdio_common.h"

void runSuccess() {
    int input;
    char buf[] = "%i";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    scanf(buf, &input);
}

void runFailure() {
    scanf(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    int input;
    char buf[] = "%i";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    scanf(buf, &input);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
