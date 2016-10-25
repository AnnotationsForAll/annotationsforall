#include "../../test_common.h"
#include <string.h>

void runSuccess() {
    char buf[] = "Hello";
    char s1[] = "e";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    strstr(buf, s1);
}

void runSuccess1() {
    char buf[] = "Hello";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    strstr(buf, buf);
}

void runFailure() {
    char s1[] = "e";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    strstr(NULL, s1);
}

void runFailure1() {
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    strstr(buf, NULL);
}

void testValues() {
    char* result;
    
    char buf[] = "Hello";
    char s1[] = "e";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';

    result = strstr(buf, s1);
    //@ assert result != \null ==> (\base_addr(result) == \base_addr(buf));
    
    if (result==NULL) {return;}
    int cmp = memcmp(result, s1, 1);
    //@ assert cmp == 0;

    //@ assert vacuous: \false;
}

void testValues1() {
    char* result;

    char buf[] = "Hello";
    char s1[] = "ll";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';

    result = strstr(buf, s1);
    //@ assert result != \null ==> (\base_addr(result) == \base_addr(buf));

    if (result==NULL) {return;}
    int cmp = memcmp(result, s1, 2);
    //@ assert cmp == 0;

    //@ assert vacuous: \false;
}
