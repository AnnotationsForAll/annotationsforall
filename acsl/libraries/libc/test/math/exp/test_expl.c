#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    expl(0.0L);
    expl(1.0L);
    expl(-1.0L);
    expl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    //result = expl(2.0);
    // assert result == \pow(M_E, 2.0);
    result = expl(1.0L);
    //@ assert result == M_E;
    result = expl(0.0L);
    //@ assert result == 1;
    result = expl(-1.0L);
    //@ assert result == 1 / M_E;
    result = expl(LDBL_MAX);
    //@ assert result == HUGE_VALL;
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
