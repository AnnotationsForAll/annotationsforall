#include "../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    char buf[] = "1";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    char* ptr;

   strtold(buf, &ptr);
}

void runSuccess2() {
    char buf[] = "1";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

   strtold(buf, NULL);
}

void runFailure() {
    char* ptr;

    strtold(NULL, &ptr);
}

void runFailure1() {
    strtold(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    long double result;
    char buf[] = "X";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    char* ptr;
    
    result = strtold(buf, &ptr);
    //@ assert \valid(ptr);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
