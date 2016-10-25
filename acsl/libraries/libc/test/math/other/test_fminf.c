#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    fminf(4.6f,1.1f);
    fminf(0.1f,3.4f);
    fminf(9.9f,2.1f);
    fminf(anyfloat(),anyfloat());
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
    result = fminf(x,y);
    //@ assert (x < y) ==> (result == x) && (x > y) ==> (result == y);
    
    x = anyfloat();
    result = fminf(x,x);
    //@ assert result == x;
    
    x = anyfloat();
    y = anyfloat();
    result = fminf(x,y);
    result2 = fminf(y,x);
    //@ assert result == result2;
    
    //x = anyfloat();
    //y = anyfloat();
    //result = fminf(x,y);
    // assert result == \min(x, y);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
