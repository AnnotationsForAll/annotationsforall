#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    sinh(0.0);
    sinh(1.0);
    sinh(-1.0);
    sinh(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    result = sinh(0.0);
    //@ assert result == 0.0;
    result = sinh(2.5);
    // assert result == \sinh(2.5);
    //result = sinh(DBL_MAX);
    // assert result == HUGE_VAL;
    // assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
