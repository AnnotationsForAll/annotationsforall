#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    fdimf(4.6f,1.1f);
    fdimf(0.1f,3.4f);
    fdimf(9.9f,2.1f);
    fdimf(anyfloat(),anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    float x,y;
    
    x = anyfloat();
    y = anyfloat();
    result = fdimf(x,y);
    //@ assert (x > y) ==> (result == x - y) && (x <= y) ==> (result == 0);
    
    //result = fdimf(FLT_MAX, FLT_MIN);
    // assert result == HUGE_VALF || result == -HUGE_VALF;
    // assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
