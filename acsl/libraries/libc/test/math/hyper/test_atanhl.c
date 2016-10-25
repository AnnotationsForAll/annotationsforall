#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < -1.0 || \result > 1.0;
extern long double outrange1();
//@ ensures \result == -1.0 || \result == 1.0;
extern long double outrange2();
//@ ensures \result >= 1.0;
extern long double inrange();

void runSuccess() {
    atanhl(1.0L);
    atanhl(0.0L);
    atanhl(-1.0L);
    atanhl(2.0L);
    atanhl(-2.0L);
    atanhl(inrange());
    atanhl(outrange1());
    atanhl(outrange2());
    atanhl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    //result = atanhl(0.5L);
    // assert \tanhl(result) == 0.5;
    
    result = atanhl(outrange1());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    result = atanhl(outrange2());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    errno = 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}