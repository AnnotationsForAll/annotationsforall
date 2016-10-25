#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    coshl(0.0L);
    coshl(1.0L);
    coshl(-1.0L);
    coshl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    result = coshl(0.0L);
    //@ assert result == 1.0;
    result = coshl(2.5L);
    // assert result == \cosh(2.5);
    result = coshl(LDBL_MAX);
    //@ assert result == HUGE_VALL;
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
