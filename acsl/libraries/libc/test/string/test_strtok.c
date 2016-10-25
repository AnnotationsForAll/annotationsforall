#include "../../test_common.h"
#include <string.h>

char* buf;

void runSuccess() {
    char buf[] = "Hello";
    char s1[] = " ";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    strtok(buf, s1);
    strtok(NULL, s1);
}

void runFailure() {
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    strtok(buf, NULL);
}

void runFailure1() {
    strtok(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    char buf[] = "Hello";
    char s1[] = " ";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    result = strtok(buf, s1);
    //@ assert result != \null ==> (\base_addr(result) == \base_addr(buf));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
