#include "../../test_common.h"
#include <string.h>

void runSuccess() {
    char buf[] = "A\0";
    char s1[] = "B";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';

    strcat(buf, s1);
}

void runFailure() {
    char buf[] = "A\0";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    strcat(buf, NULL);
}

void runFailure1() {
    char s1[] = "B";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    strcat(NULL, s1);
}

void runFailure2() {
    char buf[] = "A\0";
    char s1[] = "BB";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    strcat(buf, s1);
}

void runFailure3() {
    char buf[] = "A";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    strcat(buf, buf);
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    char buf[] = "B\0";
    char s1[] = "A";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    result = strcat(buf, s1);
    //@ assert result == buf;

    int cmp = strlen(result);
    //@ assert cmp == 2;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
