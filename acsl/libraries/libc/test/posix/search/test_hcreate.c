#include "../../../test_common.h"
#include <search.h>

void runSuccess() {
    hcreate(anysize());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    hcreate(anysize());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
