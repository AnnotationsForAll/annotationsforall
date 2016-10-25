#include "../../test_common.h"
#include <string.h>

void runSuccess() {
    char s[] = "String";
    //@ assert \valid(s+(0..\block_length(s)-1));
    //@ assert \exists integer x; s[x] == '\0';
    strlen(s);
    char s2[] = "";
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    strlen(s2);
}

void runFailure() {
    strlen(NULL);
}

void testValues() {
    char s[] = "Hello";
    //@ assert \valid(s+(0..\block_length(s)-1));
    //@ assert \exists integer x; s[x] == '\0';
    int result = strlen(s);
    //@ assert result == 5;
    
    //@ assert vacuous: \false;
}

void testValues1() {
    char s2[] = "";
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    int result = strlen(s2);
    //@ assert result == 0;
    
    //@ assert vacuous: \false;
}

void testValues2() {
    char s3[] = "One\0Two";
    //@ assert \valid(s3+(0..\block_length(s3)-1));
    //@ assert \exists integer x; s3[x] == '\0';
    int result = strlen(s3);
    //@ assert result == 3;
    
    //@ assert vacuous: \false;
}
