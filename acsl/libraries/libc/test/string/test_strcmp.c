#include "../../test_common.h"
#include <string.h>

void runSuccess() {
    char s1[] = "s1";
    char s2[] = "s2";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    strcmp(s1, s2);
}

void runSuccess1() {
    char buf[] = "s";
    char s2[] = "s2";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    strcmp(buf, s2);
}

void runSuccess2() {
    char buf[] = "s";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    strcmp(buf, buf);
}

void runFailure() {
    char s2[] = "s2";
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    strcmp(NULL, s2);
}

void runFailure1() {
    char s1[] = "s1";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    strcmp(s1, NULL);
}

void testValues() {
    int result;
    
    char s1[] = "AA";
    char s2[] = "BB";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    result = strcmp(s1, s2);
    //@ assert result != 0;
    
    //@ assert vacuous: \false;
}

void testValues1() {
    int result;
    
    char buf[] = "s";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = strcmp(buf, buf);
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
    
    result = strcmp(s3,s1);
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
    
    result = strcmp(s4,s1);
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
    
    result = strcmp(s1,s4);
    //@ assert result != 0;
    
    //@ assert vacuous: \false;
}
