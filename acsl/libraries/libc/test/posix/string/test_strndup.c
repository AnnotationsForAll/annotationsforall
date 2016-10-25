#include "../../../test_common.h"
#include <string.h>

void runSuccess() {
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    strndup(buf, anysize());
}

void runFailure() {
    strndup(NULL, anysize());
}

int f;
void testValues() {
    f = 2;
    char* result;
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = strndup(buf, 5);
    //@ assert result == \null || \valid(result);
    int cmp = strcmp(result, buf);
    //@ assert cmp == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}

int f;
void testValues1() {
    f = 2;
    char* result;
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = strndup(buf, 50);
    //@ assert result == \null || \valid(result);
    int cmp = strcmp(result, buf);
    //@ assert cmp == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}

int f;
void testValues2() {
    f = 2;
    char* result;
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = strndup(buf, 4);
    //@ assert result == \null || \valid(result);
    int cmp = strcmp(result, buf);
    //@ assert cmp != 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}

