#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    sinhl(0.0L);
    sinhl(1.0L);
    sinhl(-1.0L);
    sinhl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    result = sinhl(0.0L);
    //@ assert result == 0.0;
    result = sinhl(2.5L);
    // assert result == \sinh(2.5);
    result = sinhl(LDBL_MAX);
    //@ assert result == HUGE_VALL;
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
