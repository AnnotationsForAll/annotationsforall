#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < 0;
extern long double outrange();
//@ ensures \result > 0;
extern long double inrange();

void runSuccess() {
    log2l(1.0L);
    log2l(0.0L);
    log2l(-1.0L);
    log2l(outrange());
    log2l(inrange());
    log2l(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    //result = log2l(1.0L);
    // assert result == \log(1.0)/\log(2.0);
    result = log2l(-1.0L);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    result = log2l(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}