#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < 0;
extern long double outrange();
//@ ensures \result > 0;
extern long double inrange();

void runSuccess() {
    logl(1.0L);
    logl(0.0L);
    logl(-1.0L);
    logl(outrange());
    logl(inrange());
    logl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    //result = logl(1.0L);
    // assert result == \log(1.0);
    result = logl(-1.0L);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    result = logl(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}