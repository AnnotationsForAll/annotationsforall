#include "../../../test_common.h"
#include <math.h>
#include <stddef.h>

int quo;

void runSuccess() {
    remquof(0.1f,4.0f,&quo);
    remquof(1.2f,0.0f,&quo);
    remquof(2.0f,4.3f,&quo);
    remquof(anyfloat(),anyfloat(),&quo);
}

void runFailure() {
    remquof(0.1f,4.0f,NULL);
}

void runFailure1() {
    remquof(1.2f,0.0f,NULL);
}

void runFailure2() {
    remquof(anyfloat(),anyfloat(),NULL);
}

int f;
void testValues() {
    f = 2;
    float result;
    
    remquof(0.1f,4.0f,&quo);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
