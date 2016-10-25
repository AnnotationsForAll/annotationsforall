#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < 0;
extern float outrange();
//@ ensures \result > 0;
extern float inrange();

void runSuccess() {
    log2f(1.0f);
    log2f(0.0f);
    log2f(-1.0f);
    log2f(outrange());
    log2f(inrange());
    log2f(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    //result = log2f(1.0f);
    // assert result == \log(1.0)/\log(2.0);
    result = log2f(-1.0f);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    result = log2f(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}