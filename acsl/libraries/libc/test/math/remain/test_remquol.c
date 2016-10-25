#include "../../../test_common.h"
#include <math.h>
#include <stddef.h>

int quo;

void runSuccess() {
    remquol(0.1L,4.0L,&quo);
    remquol(1.2L,0.0L,&quo);
    remquol(2.0L,4.3L,&quo);
    remquol(anylongdouble(),anylongdouble(),&quo);
}

void runFailure() {
    remquol(0.1L,4.0L,NULL);
}

void runFailure1() {
    remquol(1.2L,0.0L,NULL);
}

void runFailure2() {
    remquol(anylongdouble(),anylongdouble(),NULL);
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    remquol(0.1L,4.0L,&quo);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
