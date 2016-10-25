#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    hypotf(1.0f, 1.0f);
    hypotf(1.0f, 0.0f);
    hypotf(8.3f, 5.0f);
    hypotf(0.0f, 121.1f);
    hypotf(anyfloat(), anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    float x,y;
    
    hypotf(anyfloat(), anyfloat());
    
    //x = anyfloat();
    //y = anyfloat();
    //result = hypotf(x,y);
    // assert result == \sqrt(\pow(x,2)+\pow(y,2));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
