#include "../../test_common.h"
#include <string.h>

void runSuccess() {
    char buf[] = "A\0";
    char s1[] = " B";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    strncat(buf, s1, 1);
}

void runFailure() {
    char buf[] = "A\0";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    strncat(buf, NULL, 1);
}

void runFailure1() {
    char s1[] = "B";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    strncat(NULL, s1, 30);
}

void runFailure2() {
    char buf[] = "A\0";
    char s1[] = " BBB";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    strncat(buf, s1, 30);
}

void runFailure3() {
    char buf[] = "A\0";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    strncat(buf, buf, 2);
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    char buf[] = "BBB\0   ";
    char s1[] = "AAA";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    result = strncat(buf, s1, 2);
    //@ assert result == buf;
    ////@ assert \forall int i; 0 <= i <= 2 ==> result[i] == 'B';
    ////@ assert \forall int i; 3 <= i <= 5 ==> result[i] == 'A';
    ////@ assert result[6] == '\0';
    
    int cmp = strlen(result);
    //@ assert cmp == 5;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
