#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    int d,n;
    ecvt(anydouble(), anyint(), &d, &n);
}

void runFailure() {
    ecvt(anydouble(), anyint(), NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    
    int d,n;
    char* result = ecvt(anydouble(), anyint(), &d, &n);
    //@ assert \valid(result);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
