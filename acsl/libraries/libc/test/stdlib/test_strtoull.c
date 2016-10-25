#include "../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    char buf[] = "1";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    char* ptr;

   strtoull(buf, &ptr, 0);
}

void runSuccess1() {
    char buf[] = "1";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    char* ptr;

   strtoull(buf, &ptr, 10);
}

void runSuccess2() {
    char buf[] = "1";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

   strtoull(buf, NULL, 0);
}

void runFailure() {
    char* ptr;

    strtoull(NULL, &ptr, 0);
}

void runFailure1() {
    strtoull(NULL, NULL, 10);
}

int f;
void testValues() {
    f = 2;
    unsigned long long int result;
    char buf[] = "X";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    char* ptr;
    
    result = strtoull(buf, &ptr, 0);
    //@ assert \valid(ptr);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
