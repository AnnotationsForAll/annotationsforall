#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    fdiml(4.6L,1.1L);
    fdiml(0.1L,3.4L);
    fdiml(9.9L,2.1L);
    fdiml(anylongdouble(),anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    long double x,y;
    
    result = fdiml(3.4L,1.2L);
    //@ assert result == 3.4 - 1.2;
    result = fdiml(1.2L,3.4L);
    //@ assert result == 0;
    
    x = anylongdouble();
    y = anylongdouble();
    result = fdiml(x,y);
    //@ assert (x > y) ==> (result == x - y) && (x <= y) ==> (result == 0);
    
    result = fdiml(LDBL_MAX, LDBL_MIN);
    //@ assert result == HUGE_VALL || result == -HUGE_VALL;
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
