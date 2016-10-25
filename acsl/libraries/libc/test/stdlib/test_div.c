#include "../../test_common.h"
#include <limits.h>
#include <stdlib.h>

/*@
@ assigns \result;
@ ensures \result != 0;
*/
extern int nonzero();

void runSuccess() {
    div(3,5);
    div(anyint(), 2);
    div(45,nonzero());
}

void runFailure() {
    div(7,0);
}

void runFailure1() {
    div(anyint(),0);
}

void runFailure2() {
    div(INT_MIN, -1);
}

int f;
void testValues() {
    f = 2;
    div_t result;
    int x;
    
    result = div(7, 2);
    //@ assert result.quot == 3 && result.rem == 1;
    result = div(6, -1);
    //@ assert result.quot == -6 && result.rem == 0;
    result = div(0, 5);
    //@ assert result.quot == 0 && result.rem == 0;
    result = div(nonzero(), 1);
    //@ assert result.rem == 0;
    result = div(0, nonzero());
    //@ assert result.quot == 0 && result.rem == 0;
    
    x = nonzero();
    result = div(x, x);
    //@ assert result.quot == 1 && result.rem == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
