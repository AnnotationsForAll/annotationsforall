#include "../../../test_common.h"
#include <string.h>

void runSuccess() {
    char buf[] = "AAA";
    char s1[] = "BB";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    stpcpy(buf, s1);
}

void runFailure() {
    char buf[] = "AAA";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    stpcpy(buf, NULL);
}

void runFailure1() {
    char s1[] = "BB";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    stpcpy(NULL, s1);
}

void runFailure2() {
    char buf[] = "AA";
    char s1[] = "BBB";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    stpcpy(buf, s1);
}

void runFailure3() {
    char buf[] = "AAA";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    stpcpy(buf, buf);
}

void testValues() {
    char* result;
    char buf[] = "BBBB";
    char s1[] = "AAA";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    result = stpcpy(buf, s1);
    //@ assert result == buf+3;
    
    //@ assert vacuous: \false;
}

void testValues1() {
    char* result;
    char buf[] = "BBBB";
    char s1[] = "AAA";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    result = stpcpy(buf, s1);
    //@ assert result[0] == '\0';
    
    //@ assert vacuous: \false;
}

