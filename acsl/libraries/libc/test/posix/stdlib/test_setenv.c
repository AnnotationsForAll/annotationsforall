#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    char s1[] = "s1";
    char s2[] = "s2";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    setenv(s1, s2, anyint());
}

void runSuccess1() {
    char s1[] = "=";
    char s2[] = "s2";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    setenv(s1, s2, anyint());
}

void runSuccess2() {
    char s1[] = "";
    char s2[] = "s2";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    setenv(s1, s2, anyint());
}

void runFailure() {
    setenv(NULL, NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    char s1[] = "s1";
    char s2[] = "s2";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    result = setenv(s1, s2, anyint());
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}

/*
void testValues1() {
    f = 2;
    int result;
    char s1[] = "=";
    char s2[] = "s2";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    result = setenv(s1, s2, anyint());
    //@ assert result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}

void testValues2() {
    f = 2;
    int result;
    char s1[] = "";
    char s2[] = "s2";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    result = setenv(s1, s2, anyint());
    //@ assert result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
*/
