#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    scalblnf(1.0f, 1);
    scalblnf(0.0f, 0);
    scalblnf(-1.0f, -1);
    scalblnf(anyfloat(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    result = scalblnf(5.0f, 3);
    // assert result = 5.0 * \pow(FLT_RADIX, 3.0);
    result = scalblnf(1.2f, 8);
    // assert result = 1.2 * \pow(FLT_RADIX, 8.3);
    result = scalblnf(FLT_MAX, INT_MAX);
    // assert result == HUGE_VALF;
    // assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
