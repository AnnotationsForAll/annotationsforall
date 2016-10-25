#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    char buf[] = "temp";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    mkstemp(buf);
}

void runFailure() {
    mkstemp(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "temp";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = mkstemp(buf);
    //@ assert result >= -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
