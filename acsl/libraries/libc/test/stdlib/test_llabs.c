#include "../../test_common.h"
#include <stdlib.h>
#include <limits.h>

/*@
    assigns \result;
    ensures \result != LLONG_MIN;
*/
extern long long getNonMinLongLong();

void runSuccess() {
    llabs(1);
    llabs(-1);
    llabs(0);
    llabs(getNonMinLongLong());
}

void runFailure() {
    llabs(LLONG_MIN);
}

int f;
void testValues() {
    f = 2;
    long long int result;
    result = llabs(1000000000);
    //@ assert result == 1000000000;
    result = llabs(0);
    //@ assert result == 0;
    result = llabs(-123445678);
    //@ assert result == 123445678;
    result = llabs(getNonMinLongLong());
    //@ assert result >= 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}

