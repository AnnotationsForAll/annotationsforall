#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    ldexpl(1.0L, 1);
    ldexpl(0.0L, 0);
    ldexpl(-1.0L, -1);
    ldexpl(anylongdouble(), 1);
    ldexpl(1.0L, anyint());
    ldexpl(anylongdouble(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    result = ldexpl(3.0L,2);
    // assert result == 3.0 * \pow(2, 2);
    result = ldexpl(5.5L,-3);
    // assert result == 5.5 * \pow(2, -3);
    result = ldexpl(LDBL_MAX, 1);
    //@ assert result == HUGE_VALL;
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
