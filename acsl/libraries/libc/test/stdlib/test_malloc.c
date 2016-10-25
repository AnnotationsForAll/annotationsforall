#include "../../test_common.h"
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>

void runSuccess() {
    malloc(1);
    malloc(10);
    malloc(0);
    malloc(INT_MAX);
    malloc(anysize());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    char* result;
    size_t x;
    
    result = malloc(10);
    //@ assert result != \null ==> \valid(result);
    result = malloc(anysize());
    //@ assert result != \null ==> \valid(result);
    
    x = anysize();
    result = malloc(x);
    //@ assert result != \null ==> \valid(result+(0..x-1));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
