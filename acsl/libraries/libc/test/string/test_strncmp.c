#include "../../test_common.h"
#include <string.h>

void runSuccess() {
    char s1[] = "s1";
    char s2[] = "s2";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    strncmp(s1, s2, 5);
}

void runSuccess1() {
    char buf[] = "A";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    strncmp(buf, buf, 30);
}

void runFailure() {
    char s2[] = "s2";
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    strncmp(NULL, s2, 5);
}

void runFailure1() {
    char s1[] = "s1";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    strncmp(s1, NULL, 5);
}

void testValues() {
    int result;
    char s1[] = "AA";
    char s2[] = "BB";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    result = strncmp(s1, s2, 2);
    //@ assert result != 0;
    
    //@ assert vacuous: \false;
}

void testValues1() {
    int result;
    char buf[] = "!";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = strncmp(buf, buf, 30);
    //@ assert result == 0;
    
    //@ assert vacuous: \false;
}

void testValues2() {
    int result;
    char s1[] = "AA";
    char s3[] = "AB";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s3+(0..\block_length(s3)-1));
    //@ assert \exists integer x; s3[x] == '\0';
    
    result = strncmp(s3,s1, 2);
    //@ assert result != 0;
    
    //@ assert vacuous: \false;
}

void testValues3() {
    int result;
    char s1[] = "AA";
    char s4[] = "A";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s4+(0..\block_length(s4)-1));
    //@ assert \exists integer x; s4[x] == '\0';
    
    result = strncmp(s4,s1,2);
    //@ assert result != 0;
    
    //@ assert vacuous: \false;
}

void testValues4() {
    int result;
    char s1[] = "AA";
    char s4[] = "A";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s4+(0..\block_length(s4)-1));
    //@ assert \exists integer x; s4[x] == '\0';
    
    result = strncmp(s1,s4,2);
    //@ assert result != 0;
    
    //@ assert vacuous: \false;
}

void testValues5() {
    int result;
    char s1[] = "AA";
    char s4[] = "A";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s4+(0..\block_length(s4)-1));
    //@ assert \exists integer x; s4[x] == '\0';
    
    result = strncmp(s4,s1,1);
    //@ assert result == 0;
    
    //@ assert vacuous: \false;
}
