#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < -1.0 || \result > 1.0;
extern float outrange();
//@ ensures -1.0 <= \result <= 1.0;
extern float inrange();

void runSuccess() {
    acosf(1.0f);
    acosf(0.0f);
    acosf(-1.0f);
    acosf(2.0f);
    acosf(-2.0f);
    acosf(inrange());
    acosf(outrange());
    acosf(INFINITY);
//    acosf(NAN);
    acosf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    //result = acosf(0.5f);
    // assert \cos(result) == 0.5f;
    
    result = acosf(2.0f);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    result = acosf(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    result = acosf(inrange());
    //@ assert 0 <= result <= M_PI;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
