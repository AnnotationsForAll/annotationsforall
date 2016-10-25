#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < 0;
extern float outrange();
//@ ensures \result > 0;
extern float inrange();

void runSuccess() {
    logf(1.0f);
    logf(0.0f);
    logf(-1.0f);
    logf(outrange());
    logf(inrange());
    logf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    //result = logf(1.0f);
    // assert result == \log(1.0);
    result = logf(-1.0f);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    result = logf(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}