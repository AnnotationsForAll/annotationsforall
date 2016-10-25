#include "../../../test_common.h"
#include <math.h>
#include <stddef.h>

void runSuccess() {
    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    nanf(buf);
}

void runSuccess1() {
    nanf(NULL);
}

int f;
void testValues() {
    f = 2;
    float result;
    
    result = nanf(NULL);
    // assert result == 0 || \is_NaN(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
