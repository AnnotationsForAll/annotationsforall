#include "../../test_common.h"
#include <inttypes.h>
#include <stdint.h>

/*@
assigns \result;
*/
extern intmax_t anyimax();
/*@
assigns \result;
ensures \result != 0;
*/
extern intmax_t nonzero();

void runSuccess() {
    imaxdiv(INTMAX_C(3),INTMAX_C(5));
    imaxdiv(INTMAX_C(500), INTMAX_C(2));
    imaxdiv(45,nonzero());
}

void runFailure() {
    imaxdiv(INTMAX_C(7),INTMAX_C(0));
}

void runFailure1() {
    imaxdiv(INTMAX_C(500),INTMAX_C(0));
}

void runFailure2() {
    imaxdiv(INTMAX_MIN, INTMAX_C(-1));
}

int f;
void testValues() {
    f = 2;
    imaxdiv_t result;
    intmax_t x;
    
    result = imaxdiv(INTMAX_C(7), INTMAX_C(2));
    //@ assert result.quot == 3 && result.rem == 1;
    result = imaxdiv(INTMAX_C(6), INTMAX_C(-1));
    //@ assert result.quot == -6 && result.rem == 0;
    result = imaxdiv(INTMAX_C(0), INTMAX_C(5));
    //@ assert result.quot == 0 && result.rem == 0;
    result = imaxdiv(INTMAX_C(500), INTMAX_C(1));
    //@ assert result.rem == 0;
    result = imaxdiv(INTMAX_C(0), nonzero());
    //@ assert result.quot == 0 && result.rem == 0;
    
    x = nonzero();
    result = imaxdiv(x, x);
    //@ assert result.quot == 1 && result.rem == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
