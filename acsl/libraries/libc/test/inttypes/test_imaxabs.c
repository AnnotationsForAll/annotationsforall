#include "../../test_common.h"
#include <inttypes.h>
#include <stdint.h>

/*@
assigns \result;
*/
extern intmax_t anyimax();
/*@
    assigns \result;
    ensures \result != INTMAX_MIN;
*/
extern int getnonminimax();

void runSuccess() {
    imaxabs(INTMAX_C(1));
    imaxabs(INTMAX_C(0));
    imaxabs(INTMAX_C(-1));
    imaxabs(INTMAX_MAX);
    imaxabs(getnonminimax());
}

void runFailure() {
    imaxabs(INTMAX_MIN);
}

int f;
void testValues() {
    f = 2;
    intmax_t result;
    
    result = imaxabs(INTMAX_C(1));
    //@ assert result == 1;
    result = imaxabs(INTMAX_C(0));
    //@ assert result == 0;
    result = imaxabs(INTMAX_C(-1));
    //@ assert result == 1;
    result = imaxabs(INTMAX_MAX);
    //@ assert result == INTMAX_MAX;
    result = imaxabs(getnonminimax());
    //@ assert result >= 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
