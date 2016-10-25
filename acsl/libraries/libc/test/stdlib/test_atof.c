#include "../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    char buf[] = "1";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    atof(buf);
}

void runFailure() {
    atof(NULL);
}

int f;
void testValues() {
    f = 2;
    double result;
    
    char buf[] = "1";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    result = atof(buf);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
