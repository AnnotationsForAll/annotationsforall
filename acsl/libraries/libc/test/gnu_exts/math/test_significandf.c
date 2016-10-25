#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    significandf(anyfloat());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    significandf(anyfloat());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
