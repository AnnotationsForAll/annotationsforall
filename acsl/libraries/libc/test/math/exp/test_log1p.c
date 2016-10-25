#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < -1;
extern double outrange();
//@ ensures \result > -1;
extern double inrange();

void runSuccess() {
    log1p(1.0);
    log1p(0.0);
    log1p(-1.0);
    log1p(outrange());
    log1p(inrange());
    log1p(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    //result = log1p(1.0);
    // assert result == \log(1 + 1.0);
    result = log1p(-2.0);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    result = log1p(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}