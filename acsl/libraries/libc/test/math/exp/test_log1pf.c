#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < -1;
extern float outrange();
//@ ensures \result > -1;
extern float inrange();

void runSuccess() {
    log1pf(1.0f);
    log1pf(0.0f);
    log1pf(-1.0f);
    log1pf(outrange());
    log1pf(inrange());
    log1pf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    //result = log1pf(1.0f);
    // assert result == \log(1 + 1.0);
    result = log1pf(-2.0f);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    result = log1pf(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}