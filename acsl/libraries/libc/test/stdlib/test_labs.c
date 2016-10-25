#include "../../test_common.h"
#include <stdlib.h>
#include <limits.h>

/*@
    assigns \result;
    ensures \result != LONG_MIN;
*/
extern long int getNonMinLong();

void runSuccess() {
    labs(54);
    labs(-978);
    labs(getNonMinLong());
}

void runFailure() {
    labs(LONG_MIN);
}

int f;
void testValues() {
    f = 2;
    long int result;
    result = labs(85);
    //@ assert result == 85;
    result = labs(-65482);
    //@ assert result == 65482;
    result = labs(getNonMinLong());
    //@ assert result >= 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}

