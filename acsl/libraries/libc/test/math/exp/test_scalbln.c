#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    scalbln(1.0, 1);
    scalbln(0.0, 0);
    scalbln(-1.0, -1);
    scalbln(anydouble(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    result = scalbln(5.0, 3);
    // assert result = 5.0 * \pow(FLT_RADIX, 3.0);
    result = scalbln(1.2, 8);
    // assert result = 1.2 * \pow(FLT_RADIX, 8.3);
    result = scalbln(DBL_MAX, INT_MAX);
    // assert result == HUGE_VAL;
    // assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
