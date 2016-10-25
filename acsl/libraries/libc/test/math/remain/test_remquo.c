#include "../../../test_common.h"
#include <math.h>
#include <stddef.h>

int quo;

void runSuccess() {
    remquo(0.1,4.0,&quo);
    remquo(1.2,0.0,&quo);
    remquo(2.0,4.3,&quo);
    remquo(anydouble(),anydouble(),&quo);
}

void runFailure() {
    remquo(0.1,4.0,NULL);
}

void runFailure1() {
    remquo(1.2,0.0,NULL);
}

void runFailure2() {
    remquo(anydouble(),anydouble(),NULL);
}

int f;
void testValues() {
    f = 2;
    double result;
    
    remquo(0.1,4.0,&quo);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
