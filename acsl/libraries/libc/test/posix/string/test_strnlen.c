#include "../../../test_common.h"
#include <string.h>

void runSuccess() {
    char s[] = "String";
    strnlen(s, anysize());
    char s2[] = "";
    strnlen(s2, anysize());
}

void runFailure() {
    strnlen(NULL, anysize());
}

void testValues() {
    char s[] = "Hello";
    //@ assert \valid(s+(0..\block_length(s)-1));
    //@ assert \exists integer x; s[x] == '\0';
    int result = strnlen(s, 100);
    //@ assert result == 5;
    
    //@ assert vacuous: \false;
}

void testValues1() {
    char s2[] = "";
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    int result = strnlen(s2, anysize());
    //@ assert result == 0;
    
    //@ assert vacuous: \false;
}

void testValues2() {
    char s3[] = "One\0Two";
    //@ assert \valid(s3+(0..\block_length(s3)-1));
    //@ assert \exists integer x; s3[x] == '\0';
    size_t x = anysize();
    int result = strnlen(s3, x);
    //@ assert result <= 3;
    //@ assert result <= x;
    
    //@ assert vacuous: \false;
}
