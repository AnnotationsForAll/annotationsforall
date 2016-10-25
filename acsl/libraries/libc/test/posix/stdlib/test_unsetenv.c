#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    char buf[] = "a";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    unsetenv(buf);
}

void runFailure() {
    unsetenv(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "a";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = unsetenv(buf);
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}

/*void testValues1() {
    f = 2;
    int result;
    char buf[] = "=";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = unsetenv(buf);
    //@ assert result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}*/
