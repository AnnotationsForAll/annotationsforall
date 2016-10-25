#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

/*@
assigns \result;
ensures \result != 0;
*/
extern float nonzero();

void runSuccess() {
    atan2f(1.0f,1.0f);
    atan2f(0.0f,1.0f);
    atan2f(1.0f,0.0f);
    atan2f(anydouble(), nonzero());
    atan2f(nonzero(), anydouble());
    atan2f(nonzero(), nonzero());
    atan2f(0.0f,0.0f);
    atan2f(anydouble(), anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    //result = atan2f(1.0f,2.0f);
    // assert \tan(result) == 1.0f/2.0f;
    
    result = atan2f(nonzero(),nonzero());
    //@ assert -M_PI <= result <= M_PI;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
