#include "../../../test_common.h"
#include <string.h>

void runSuccess() {
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    strdup(buf);
}

void runFailure() {
    strdup(NULL);
}

int f;
void testValues() {
    f = 2;
    char* result;
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = strdup(buf);
    //@ assert result == \null || \valid(result);
    int cmp = strcmp(result, buf);
    //@ assert cmp == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
