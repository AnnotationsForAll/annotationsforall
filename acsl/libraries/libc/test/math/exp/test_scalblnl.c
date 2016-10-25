#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    scalblnl(1.0L, 1.0L);
    scalblnl(0.0L, 0.0L);
    scalblnl(-1.0L, -1.0L);
    scalblnl(anylongdouble(), anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    result = scalblnl(5.0L, 3.0L);
    // assert result = 5.0 * \pow(FLT_RADIX, 3.0);
    result = scalblnl(1.2L, 8.2L);
    // assert result = 1.2 * \pow(FLT_RADIX, 8.3);
    result = scalblnl(LDBL_MAX, LDBL_MAX);
    //@ assert result == HUGE_VALL;
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
