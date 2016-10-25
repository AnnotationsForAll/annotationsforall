#include "../../../stdio_common.h"
#include <stdio.h>

void runSuccess() {
    cuserid(NULL);
}

void runSuccess1() {
    char buf[L_cuserid];
    //@ assert \valid(buf+(0..( L_cuserid )-1));
    cuserid(buf);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    char buf[L_cuserid];
    //@ assert \valid(buf+(0..( L_cuserid )-1));
    char* result = cuserid(buf);
    //@ assert result == buf;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
