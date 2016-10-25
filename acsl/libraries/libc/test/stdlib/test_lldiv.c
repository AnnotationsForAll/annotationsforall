#include "../../test_common.h"
#include <limits.h>
#include <stdlib.h>

/*@
@ assigns \result;
@ ensures \result != 0;
*/
extern long long int nonzero();

void runSuccess() {
    lldiv(3LL,5LL);
    lldiv(anylonglong(), 2LL);
    lldiv(45LL,nonzero());
}

void runFailure() {
    lldiv(7LL,0LL);
}

void runFailure1() {
    lldiv(anylonglong(),0LL);
}

void runFailure2() {
    lldiv(LLONG_MIN, -1LL);
}

int f;
void testValues() {
    f = 2;
    lldiv_t result;
    long long int x;
    
    result = lldiv(7LL, 2LL);
    //@ assert result.quot == 3 && result.rem == 1;
    result = lldiv(6LL, -1LL);
    //@ assert result.quot == -6 && result.rem == 0;
    result = lldiv(0LL, 5LL);
    //@ assert result.quot == 0 && result.rem == 0;
    result = lldiv(nonzero(), 1LL);
    //@ assert result.rem == 0;
    result = lldiv(0LL, nonzero());
    //@ assert result.quot == 0 && result.rem == 0;
    
    x = nonzero();
    result = lldiv(x, x);
    //@ assert result.quot == 1 && result.rem == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
