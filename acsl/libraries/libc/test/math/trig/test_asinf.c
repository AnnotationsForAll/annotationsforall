#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < -1.0 || \result > 1.0;
extern float outrange();
//@ ensures -1.0 <= \result <= 1.0;
extern float inrange();

void runSuccess() {
    asinf(1.0f);
    asinf(0.0f);
    asinf(-1.0f);
    asinf(2.0f);
    asinf(-2.0f);
    asinf(inrange());
    asinf(outrange());
    asinf(INFINITY);
//    asinf(NAN);
    asinf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    //result = asinf(0.5f);
    // assert \sin(result) == 0.5f;
    
    result = asinf(2.0f);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    result = asinf(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    result = asinf(inrange());
    //@ assert -M_PI/2.0 <= result <= M_PI/2.0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
