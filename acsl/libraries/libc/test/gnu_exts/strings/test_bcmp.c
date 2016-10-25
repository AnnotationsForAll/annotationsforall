#include "../../../test_common.h"
#include <strings.h>

void runSuccess() {
    char buf[] = "first 30 characters are valid";
    char s1[] = "string1";
    char s2[] = "string2";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    
    bcmp(s1, s2, 5);
    bcmp(buf, s2, 8);
    bcmp(buf, buf, 30);
}

void runFailure() {
    char s2[] = "string2";
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    bcmp(NULL, s2, 5);
}

void runFailure1() {
    char s1[] = "string1";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    bcmp(s1, NULL, 5);
}

void runFailure2() {
    char s1[] = "AAA";
    char s2[] = "BBB";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    
    bcmp(s1, s2, 97);
}

void runFailure3() {
    char s1[] = "longer";
    char s2[] = "shrt";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    
    bcmp(s1, s2, 7);
}

void testValues() {
    char s1[] = "AA";
    char s2[] = "BB";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    
    int result = bcmp(s1, s2, 2);
    //@ assert result != 0;
    
    //@ assert vacuous: \false;
}

void testValues1() {
    char buf[] = "STRING";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    
    int result = bcmp(buf, buf, 7);
    //@ assert result == 0;
    
    //@ assert vacuous: \false;
}

void testValues2() {
    char s1[] = "AA";
    char s3[] = "AB";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \valid(s3+(0..\block_length(s3)-1));
    
    int result = bcmp(s3, s1, 2);
    //@ assert result != 0;
    
    //@ assert vacuous: \false;
}
