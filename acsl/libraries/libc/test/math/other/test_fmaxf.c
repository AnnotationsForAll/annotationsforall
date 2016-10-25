#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    fmaxf(4.6f,1.1f);
    fmaxf(0.1f,3.4f);
    fmaxf(9.9f,2.1f);
    fmaxf(anyfloat(),anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result,result2;
    float x,y;
    
    x = anyfloat();
    y = anyfloat();
    result = fmaxf(x,y);
    //@ assert (x > y) ==> (result == x) && (x < y) ==> (result == y);
    
    x = anyfloat();
    result = fmaxf(x,x);
    //@ assert result == x;
    
    x = anyfloat();
    y = anyfloat();
    result = fmaxf(x,y);
    result2 = fmaxf(y,x);
    //@ assert result == result2;
    
    //x = anyfloat();
    //y = anyfloat();
    //result = fmaxf(x,y);
    // assert result == \max(x, y);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
