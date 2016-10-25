#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < 0;
extern float outrange();
//@ ensures \result > 0;
extern float inrange();

void runSuccess() {
    log10f(1.0f);
    log10f(0.0f);
    log10f(-1.0f);
    log10f(outrange());
    log10f(inrange());
    log10f(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    //result = log10f(1.0f);
    // assert result == \log10(1.0);
    result = log10f(-1.0f);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    result = log10f(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}