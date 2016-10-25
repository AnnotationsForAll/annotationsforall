#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

/*@
assigns \result;
ensures \result != 0;
*/
extern long double nonzero();

void runSuccess() {
    atan2l(1.0L,1.0L);
    atan2l(0.0L,1.0L);
    atan2l(1.0L,0.0L);
    atan2l(anydouble(), nonzero());
    atan2l(nonzero(), anydouble());
    atan2l(nonzero(), nonzero());
    atan2l(0.0L,0.0L);
    atan2l(anydouble(), anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    //result = atan2l(1.0L,2.0L);
    // assert \tan(result) == 1.0L/2.0L;
    
    result = atan2l(nonzero(),nonzero());
    //@ assert -M_PI <= result <= M_PI;
    
    result = atan2l(0.0L,0.0L);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
