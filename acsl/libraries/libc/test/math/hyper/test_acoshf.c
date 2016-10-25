#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < 1.0;
extern float outrange();
//@ ensures \result >= 1.0;
extern float inrange();

void runSuccess() {
    acoshf(1.0f);
    acoshf(0.0f);
    acoshf(-1.0f);
    acoshf(2.0f);
    acoshf(-2.0f);
    acoshf(NAN);
    acoshf(INFINITY);
    acoshf(inrange());
    acoshf(outrange());
    acoshf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    //result = acoshf(0.5f);
    // assert \coshf(result) == 0.5;
    
    result = acoshf(2.0f);
    //@ assert result >= 0;
    errno = 0;
    
    result = acoshf(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
