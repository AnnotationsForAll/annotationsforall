#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    char s1[] = "s1";
    char s2[PATH_MAX];
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    realpath(s1, s2);
}

void runSuccess1() {
    char s1[] = "s1";
    char s2[PATH_MAX];
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    realpath(s1, NULL);
}

void runFailure() {
    realpath(NULL, NULL);
}

void runFailure1() {
    char s1[] = "s1";
    char s2[PATH_MAX];
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    realpath(s1, s1);
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    char s1[] = "s1";
    char s2[PATH_MAX];
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    result = realpath(s1, s2);
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
