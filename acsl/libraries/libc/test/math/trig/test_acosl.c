/**
 * Expect failure because wp unimplemented feature: long double
 */
#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < -1.0 || \result > 1.0;
extern long double outrange();
//@ ensures -1.0 <= \result <= 1.0;
extern long double inrange();

void runSuccess() {
    acosl(1.0L);
    acosl(0.0L);
    acosl(-1.0L);
    acosl(2.0L);
    acosl(-2.0L);
    acosl(inrange());
    acosl(outrange());
    acosl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    //result = acos(0.5L);
    // assert \cos(result) == 0.5L;
    
    result = acosl(2.0L);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    result = acosl(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    result = acosl(inrange());
    //@ assert 0 <= result <= M_PI;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
