#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < -1.0 || \result > 1.0;
extern float outrange1();
//@ ensures \result >= 1.0;
extern float inrange();

void runSuccess() {
    atanhf(1.0f);
    atanhf(0.0f);
    atanhf(-1.0f);
    atanhf(2.0f);
    atanhf(-2.0f);
    atanhf(INFINITY);
    atanhf(inrange());
    atanhf(outrange1());
    atanhf(outrange2());
    atanhf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    //result = atanhf(0.5f);
    // assert \tanhf(result) == 0.5;
    
    result = atanhf(outrange1());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
