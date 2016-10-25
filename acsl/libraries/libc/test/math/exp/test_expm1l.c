#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    expm1l(0.0L);
    expm1l(1.0L);
    expm1l(-1.0L);
    expm1l(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    //result = expm1l(2.0L);
    // assert result == \pow(M_E, 2.0) - 1;
    result = expm1l(1.0L);
    //@ assert result == M_E - 1;
    result = expm1l(0.0L);
    //@ assert result == 1;
    result = expm1l(-1.0L);
    //@ assert result == 1 / M_E - 1;
    result = expm1l(LDBL_MAX);
    //@ assert result == HUGE_VALL;
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
