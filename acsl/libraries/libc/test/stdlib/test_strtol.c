#include "../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    char buf[] = "1";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    char* ptr;

   strtol(buf, &ptr, 0);
}

void runSuccess1() {
    char buf[] = "1";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    char* ptr;

   strtol(buf, &ptr, 10);
}

void runSuccess2() {
    char buf[] = "1";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

   strtol(buf, NULL, 0);
}

void runFailure() {
    char* ptr;

    strtol(NULL, &ptr, 0);
}

void runFailure1() {
    strtol(NULL, NULL, 10);
}

int f;
void testValues() {
    f = 2;
    long int result;
    char buf[] = "X";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    char* ptr;
    
    result = strtol(buf, &ptr, 0);
    //@ assert \valid(ptr);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
