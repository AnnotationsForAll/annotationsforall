#include "../../../test_common.h"
#include <string.h>

void runSuccess() {
    char buf[] = "first 30 characters are valid";
    char s1[] = "Hello";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    
    memccpy(buf, s1, anyint(), 5);
    memccpy(buf, s1, anyint(), 2);
}

void runFailure() {
    char buf[] = "first 30 characters are valid";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    memccpy(buf, NULL, anyint(), 5);
}

void runFailure1() {
    char buf[] = "first 30 characters are valid";
    char s1[] = "Hello";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    
    memccpy(NULL, s1, anyint(), 5);
}

void runFailure2() {
    char buf[] = "first 30 characters are valid";
    char s1[] = "Hello";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    
    memccpy(buf, s1, anyint(), 20);
}

void runFailure3() {
    char buf[] = "first 30 characters are valid";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    memccpy(buf, buf, anyint(), 30);
}

void testValues() {
    char* result;
    char buf[] = "BB";
    char s1[] = "A!!";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    
    result = memccpy(buf, s1, '!', 1);
    //@ assert result == NULL ||  \base_addr(buf) == \base_addr(result);
    // assert result == buf;
    // assert result[0] == 'A';
    // assert result[1] == 'B';
    // assert result[2] == '\0';
    
    //@ assert vacuous: \false;
}

void testValues1() {
    char* result;
    char buf[] = "BB";
    char s1[] = "A!!";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    
    result = memccpy(buf, s1, '!', 3);
    //@ assert result == NULL || \base_addr(buf) == \base_addr(result);
    // assert result == buf;
    // assert result[0] == 'A';
    // assert result[1] == '!';
    // assert result[2] == '\0';
    
    //@ assert vacuous: \false;
}
