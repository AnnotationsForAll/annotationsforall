#include "../../test_common.h"
#include <string.h>

void runSuccess() {
    char buf[] = "BB";
    char s1[] = "AA";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    
    memcpy(buf, s1, 2);
}

void runSuccess1() {
    char buf[] = "BB";
    char s1[] = "AA";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \valid(s1+(0..\block_length(s1)-1));

    memcpy(buf, s1, 1);
}

void runFailure() {
    char buf[] = "AA";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    memcpy(buf, NULL, anysize());
}

void runFailure1() {
    char s1[] = "BB";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    
    memcpy(NULL, s1, anysize());
}

void runFailure2() {
    char buf[] = "BB";
    char s1[] = "AA";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    
    memcpy(buf, s1, 20);
}

void runFailure3() {
    char buf[] = "BB";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    memcpy(buf, buf, 2);
}

void testValues() {
    char* result;
    char buf[] = "BB";
    char s1[] = "A";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    
    result = memcpy(buf, s1, 1);
    //@ assert result == buf;
    ////@ assert result[0] == 'A';
    ////@ assert result[1] == 'B';
    ////@ assert result[2] == '\0';
    
    int cmp = memcmp(buf, s1, 1);
    //@ assert cmp == 0;

    //@ assert vacuous: \false;
}

void testValues1() {
    char* result;
    char buf[] = "BB";
    char s1[] = "A";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    
    result = memcpy(buf, s1, 0);
    //@ assert result == buf;
    ////@ assert result[0] == 'B';
    ////@ assert result[1] == 'B';
    ////@ assert result[2] == '\0';
    
    int cmp = memcmp(buf, s1, 0);
    //@ assert cmp == 0;

    //@ assert vacuous: \false;
}

void testValues2() {
    char* result;
    char buf[] = "BBB";
    char s1[] = "A";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    
    result = memcpy(buf, s1, 2);
    //@ assert result == buf;
    ////@ assert result[0] == 'A';
    ////@ assert result[1] == '\0';
    ////@ assert result[2] == 'B';
    ////@ assert result[3] == '\0';
    
    int cmp = memcmp(buf, s1, 2);
    //@ assert cmp == 0;

    //@ assert vacuous: \false;
}
