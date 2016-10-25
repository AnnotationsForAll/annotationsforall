#include "../../test_common.h"
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void runSuccess() {
    getenv("");
    getenv("PATH");
}

void runFailure() {
    getenv(NULL);
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    result = getenv("");
    //@ assert result == \null || \valid(result);
    result = getenv("PATH");
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}