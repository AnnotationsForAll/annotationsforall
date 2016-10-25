#include "../../../stdio_common.h"
#include <stdio.h>

void runSuccess() {
    char* p;
    asprintf(&p, anystring());
}

void runFailure() {
    asprintf(NULL, anystring());
}

void runFailure1() {
    char* p;
    asprintf(&p, NULL);
}


int f;
void testValues() {
    f = 2;
    
    char* p;
    asprintf(&p, anystring());
    //@ assert \valid(p);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
