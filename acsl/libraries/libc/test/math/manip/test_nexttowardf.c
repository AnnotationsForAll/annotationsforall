#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    nexttowardf(1.3f,6.5L);
    nexttowardf(1.0f,-3.0L);
    nexttowardf(4.5f,4.5L);
    nexttowardf(anyfloat(),anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    float x,y;
    
    x = anyfloat();
    result = nexttowardf(x,(long double)x);
    //@ assert result == x;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}