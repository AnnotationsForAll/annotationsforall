#include "../../test_common.h"
#include <string.h>

void runSuccess() {
    char s1[] = "A";
    char s2[] = "B";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    strpbrk(s1, s2);
}

void runSuccess1() {
    char s1[] = "A";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    strpbrk(s1, s1);
}

void runFailure() {
    char s1[] = "A";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    strpbrk(NULL, s1);
}

void runFailure1() {
    char s1[] = "A";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    strpbrk(s1, NULL);
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    char s1[] = "s1";
    char s2[] = "s2";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    result = strpbrk(s1, s2);
    //@ assert result != \null ==> (\base_addr(result) == \base_addr(s1));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
