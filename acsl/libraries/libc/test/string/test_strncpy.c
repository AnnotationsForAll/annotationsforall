#include "../../test_common.h"
#include <string.h>

void runSuccess() {
    char buf[] = "AA";
    char s1[] = "B";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    strncpy(buf, s1, 1);
}

void runFailure() {
    char buf[] = "A";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    strncpy(buf, NULL, 5);
}

void runFailure1() {
    char s1[] = "A";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    strncpy(NULL, s1, 6);
}

void runFailure3() {
    char buf[] = "AA";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    strncpy(buf, buf, 1);
}

int f;
void testValues() {
    f = 2;
    char* result;
    char buf[] = "BBB";
    char s1[] = "AAA";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    result = strncpy(buf, s1, 2);
    //@ assert result == buf;

    int cmp = memcmp(buf, s1, 2);
    //@ assert cmp == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
