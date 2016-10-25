#include "../../test_common.h"
#include <string.h>

void runSuccess() {
    char s1[] = "s1";
    char s2[] = "s2";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    strcoll(s1, s2);
}

void runSuccess2() {
    char buf[] = "s";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    strcoll(buf, buf);
}

void runFailure() {
    char s2[] = "s2";
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    strcoll(NULL, s2);
}

void runFailure1() {
    char s1[] = "s1";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    strcoll(s1, NULL);
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
    
    strcoll(s1, s2);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
