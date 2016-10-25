#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < 0;
extern double outrange();
//@ ensures \result > 0;
extern double inrange();

void runSuccess() {
    log10(1.0);
    log10(0.0);
    log10(-1.0);
    log10(outrange());
    log10(inrange());
    log10(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    //result = log10(1.0);
    // assert result == \log10(1.0);
    result = log10(-1.0);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    result = log10(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}