#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < 0;
extern double outrange();
//@ ensures \result > 0;
extern double inrange();

void runSuccess() {
    log(1.0);
    log(0.0);
    log(-1.0);
    log(outrange());
    log(inrange());
    log(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    errno = 0;
    result = log(1.0);
    //@ assert result == 0 && errno == 0;
    result = log(-1.0);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    result = log(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
