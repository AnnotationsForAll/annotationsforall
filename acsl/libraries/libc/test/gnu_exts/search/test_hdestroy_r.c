#include "../../../test_common.h"
#include <search.h>

void runSuccess() {
    struct hsearch_data htab;
    if (!hcreate_r(anysize(), &htab)) {return;}

    hdestroy_r(&htab);
}

void runSuccess1() {
    hdestroy_r(NULL);
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;

    hdestroy_r(NULL);
    //@ assert errno == EINVAL;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
