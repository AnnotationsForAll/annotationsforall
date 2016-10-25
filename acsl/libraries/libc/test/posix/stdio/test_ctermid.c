#include "../../../test_common.h"
#include <stdio.h>

void runSuccess() {
    ctermid(NULL);
}

void runSuccess1() {
    char buf[L_ctermid];
    ctermid(buf);
}

void runFailure() {
    char buf[1]; //value is less than required size of L_ctermid
    ctermid(buf);
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    result = ctermid(NULL);
    //@ assert \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}

void testValues1() {
    f = 2;
    char* result;
    char buf[L_ctermid];
    
    result = ctermid(buf);
    //@ assert result == buf;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
