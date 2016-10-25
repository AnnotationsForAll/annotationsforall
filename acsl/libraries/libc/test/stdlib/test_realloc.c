#include "../../test_common.h"
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>

void runSuccess() {
    void* p = realloc(NULL,anysize());
    p = realloc(p, 20);
    p = realloc(p, anysize());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    char* result;
    size_t x;
    
    result = realloc(NULL, 10);
    //@ assert result != \null ==> \valid(result);
    result = realloc(result, anysize());
    //@ assert result != \null ==> \valid(result);
    
    x = anysize();
    result = realloc(result, x);
    //@ assert result != \null ==> \valid(result+(0..x-1));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
