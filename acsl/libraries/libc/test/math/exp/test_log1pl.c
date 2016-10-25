#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < -1;
extern long double outrange();
//@ ensures \result > -1;
extern long double inrange();

void runSuccess() {
    log1pl(1.0L);
    log1pl(0.0L);
    log1pl(-1.0L);
    log1pl(outrange());
    log1pl(inrange());
    log1pl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    //result = log1pl(1.0L);
    // assert result == \log(1 + 1.0);
    result = log1pl(-2.0L);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    result = log1pl(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}