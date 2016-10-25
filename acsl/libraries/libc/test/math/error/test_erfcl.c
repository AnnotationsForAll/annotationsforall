#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    erfcl(0.0L);
    erfcl(1.0L);
    erfcl(-1.0L);
    erfcl(56.5L);
    erfcl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    erfcl(anylongdouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
