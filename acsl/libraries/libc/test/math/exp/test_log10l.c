#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < 0;
extern long double outrange();
//@ ensures \result > 0;
extern long double inrange();

void runSuccess() {
    log10l(1.0L);
    log10l(0.0L);
    log10l(-1.0L);
    log10l(outrange());
    log10l(inrange());
    log10l(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    //result = log10l(1.0L);
    // assert result == \log10(1.0);
    result = log10l(-1.0L);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    result = log10l(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}