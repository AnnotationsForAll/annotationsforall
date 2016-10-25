#include "../../test_common.h"
#include <stdlib.h>
#include <limits.h>

/*@
    assigns \result;
    ensures \result != INT_MIN;
*/
extern int getNonMinInt();

void runSuccess() {
    abs(4);
    abs(-99);
    abs(getNonMinInt());
}

void runFailure() {
    abs(INT_MIN);
}

int f;
void testValues() {
    f = 2;
    int result;
    result = abs(4);
    //@ assert result == 4;
    result = abs(-83);
    //@ assert result == 83;
    result = abs(getNonMinInt());
    //@ assert result >= 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}

