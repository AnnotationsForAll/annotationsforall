#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

/*@
assigns \result;
ensures \result != 0;
*/
extern double nonzero();

void runSuccess() {
    atan2(1.0,1.0);
    atan2(0.0,1.0);
    atan2(1.0,0.0);
    atan2(anydouble(), nonzero());
    atan2(nonzero(), anydouble());
    atan2(nonzero(), nonzero());
    atan2(0.0,0.0);
    atan2(anydouble(), anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    //result = atan2(1.0,2.0);
    // assert \tan(result) == 1.0/2.0;
    
    result = atan2(nonzero(),nonzero());
    //@ assert -M_PI <= result <= M_PI;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
