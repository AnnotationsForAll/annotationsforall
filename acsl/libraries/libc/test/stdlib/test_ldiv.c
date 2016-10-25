#include "../../test_common.h"
#include <limits.h>
#include <stdlib.h>

/*@
@ assigns \result;
@ ensures \result != 0;
*/
extern long int nonzero();

void runSuccess() {
    ldiv(3L,5L);
    ldiv(anylong(), 2L);
    ldiv(45L,nonzero());
}

void runFailure() {
    ldiv(7L,0L);
}

void runFailure2() {
    ldiv(anylong(),0L);
}

void runFailure3() {
    ldiv(LONG_MIN, -1L);
}

int f;
void testValues() {
    f = 2;
    ldiv_t result;
    long int x;
    
    result = ldiv(7L, 2L);
    //@ assert result.quot == 3 && result.rem == 1;
    result = ldiv(6L, -1L);
    //@ assert result.quot == -6 && result.rem == 0;
    result = ldiv(0L, 5L);
    //@ assert result.quot == 0 && result.rem == 0;
    result = ldiv(nonzero(), 1L);
    //@ assert result.rem == 0;
    result = ldiv(0L, nonzero());
    //@ assert result.quot == 0 && result.rem == 0;
    
    x = nonzero();
    result = ldiv(x, x);
    //@ assert result.quot == 1 && result.rem == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
