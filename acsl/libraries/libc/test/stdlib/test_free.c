#include "../../test_common.h"
#include <stdlib.h>
#include <stddef.h>

void runSuccess() {
    void* test1 = malloc(anysize());
    void* result;
    
    result = malloc(10);
    free(result);
    
    result = malloc(anysize());
    free(result);
    
    free(NULL);
    
    free(test1);
}

// Double free
void runFailure() {
    void* test1 = malloc(anysize());

    free(test1);
    free(test1);
}

// not returned by calloc, malloc, or realloc
void runFailure2() {
    void* result;

    free(result);
}

int f;
void testValues() {
    f = 2;
    void* result;
    
    result = malloc(10);
    free(result);
    //@ assert result == \null || \allocable(result);
    
    result = malloc(anysize());
    free(result);
    //@ assert result == \null || \allocable(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
