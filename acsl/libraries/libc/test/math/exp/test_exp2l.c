#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    exp2l(0.0L);
    exp2l(1.0L);
    exp2l(-1.0L);
    exp2l(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    //result = exp2l(2.0L);
    // assert result == \pow(2, 2.0);
    result = exp2l(1.0L);
    //@ assert result == 2;
    result = exp2l(0.0L);
    //@ assert result == 1;
    result = exp2l(-1.0L);
    //@ assert result == 0.5L;
    result = exp2(LDBL_MAX);
    //@ assert result == HUGE_VALL;
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
