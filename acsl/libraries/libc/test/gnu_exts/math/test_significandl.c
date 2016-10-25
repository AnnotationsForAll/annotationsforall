#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    significandl(anylongdouble());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    significandl(anylongdouble());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
