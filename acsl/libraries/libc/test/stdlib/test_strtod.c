#include "../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    char buf[] = "1";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    char* ptr;

   strtod(buf, &ptr);
}

void runSuccess2() {
    char buf[] = "1";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

   strtod(buf, NULL);
}

void runFailure() {
    char* ptr;

    strtod(NULL, &ptr);
}

void runFailure1() {
    strtod(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    double result;
    char buf[] = "X";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    char* ptr;
    
    result = strtod(buf, &ptr);
    //@ assert \valid(ptr);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
