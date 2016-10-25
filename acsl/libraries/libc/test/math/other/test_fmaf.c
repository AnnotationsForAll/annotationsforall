#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    fmaf(1.0f,2.0f,3.0f);
    fmaf(5.6f,7.5f,6.8f);
    fmaf(anyfloat(),anyfloat(),anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    float x,y,z;
    
    result = fmaf(1.0f,2.0f,3.0f);
    //@ assert result == 5.0;
    
    x = anyfloat();
    y = anyfloat();
    z = anyfloat();
    result = fmaf(x,y,z);
    //@ assert result == (x*y)+z;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
