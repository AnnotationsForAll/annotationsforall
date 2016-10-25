#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < -1.0 || \result > 1.0;
extern double outrange1();
//@ ensures -1.0 < \result && \result < 1.0;
extern double inrange();

void runSuccess() {
    atanh(1.0);
    atanh(0.0);
    atanh(-1.0);
    atanh(2.0);
    atanh(-2.0);
    atanh(inrange());
    atanh(outrange1());
    atanh(outrange2());
    atanh(anydouble());
    //@ assert vacuous: \false;
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    //result = atanh(0.5);
    // assert \tanh(result) == 0.5;
    
    result = atanh(outrange1());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
