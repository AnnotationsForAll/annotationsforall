#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    fdim(4.6,1.1);
    fdim(0.1,3.4);
    fdim(9.9,2.1);
    fdim(anydouble(),anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    double x,y;
    
    result = fdim(3.4,1.2);
    //@ assert result == 3.4 - 1.2;
    result = fdim(1.2,3.4);
    //@ assert result == 0;
    
    x = anydouble();
    y = anydouble();
    result = fdim(x,y);
    //@ assert (x > y) ==> (result == x - y) && (x <= y) ==> (result == 0);
    
    //result = fdim(DBL_MAX, DBL_MIN);
    // assert result == HUGE_VAL || result == -HUGE_VAL;
    // assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
