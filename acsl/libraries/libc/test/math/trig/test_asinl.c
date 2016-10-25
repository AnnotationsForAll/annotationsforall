#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < -1.0 || \result > 1.0;
extern long double outrange();
//@ ensures -1.0 <= \result <= 1.0;
extern long double inrange();

void runSuccess() {
    asinl(1.0L);
    asinl(0.0L);
    asinl(-1.0L);
    asinl(2.0L);
    asinl(-2.0L);
    asinl(inrange());
    asinl(outrange());
    asinl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    //result = asin(0.5L);
    // assert \sin(result) == 0.5L;
    
    result = asinl(2.0L);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    result = asinl(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    result = asinl(inrange());
    //@ assert -M_PI/2.0 <= result <= M_PI/2.0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}