#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    scalbn(1.0, 1);
    scalbn(0.0, 0);
    scalbn(-1.0, -1);
    scalbn(anydouble(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    result = scalbn(5.0, 3);
    // assert result = 5.0 * \pow(FLT_RADIX, 3.0);
    result = scalbn(1.2, 8);
    // assert result = 1.2 * \pow(FLT_RADIX, 8.3);
    result = scalbn(DBL_MAX, INT_MAX);
    // assert result == HUGE_VAL;
    // assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
