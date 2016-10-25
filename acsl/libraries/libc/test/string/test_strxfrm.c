#include "../../test_common.h"
#include <string.h>

char* buf;

void runSuccess() {
    char buf[] = "first 30 characters are valid";
    char s1[] = "to transform";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
pre_fnct:
    strxfrm(buf, s1, 5);
    //@ assert \forall integer i; 0 <= i < 29 ==> \at(s1[i], pre_fnct) == s1[i];
    strxfrm(NULL, s1, 0);
}

void runFailure() {
    char buf[] = "first 30 characters are valid";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    strxfrm(buf, buf, 30);
}

void runFailure1() {
    char buf[] = "first 30 characters are valid";
    char s1[] = "to transform";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    strxfrm(NULL, s1, 10);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    char buf[] = "first 30 characters are valid";
    char s1[] = "to transform";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    strxfrm(buf, s1, 5);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
