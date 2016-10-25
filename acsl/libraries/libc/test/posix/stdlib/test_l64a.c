#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    l64a(5L);
}

void runFailure() {
    l64a(-3L);
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    result = l64a(53L);
    //@ assert \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
