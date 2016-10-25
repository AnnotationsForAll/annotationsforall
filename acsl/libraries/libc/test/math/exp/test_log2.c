#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < 0;
extern double outrange();
//@ ensures \result > 0;
extern double inrange();

void runSuccess() {
    log2(1.0);
    log2(0.0);
    log2(-1.0);
    log2(outrange());
    log2(inrange());
    log2(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    //result = log2(1.0);
    // assert result == \log(1.0)/\log(2.0);
    result = log2(-1.0);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    result = log2(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}