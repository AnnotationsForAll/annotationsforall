#include "../../../test_common.h"
#include <search.h>

void runSuccess() {
    struct hsearch_data htab;
    hcreate_r(anysize(), &htab);
}

void runSuccess1() {
    struct hsearch_data htab;
    hcreate_r(anysize(), NULL);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    struct hsearch_data htab;
    hcreate_r(anysize(), NULL);
    //@ assert errno == EINVAL;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
