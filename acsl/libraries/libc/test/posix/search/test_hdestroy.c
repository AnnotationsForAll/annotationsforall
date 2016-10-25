#include "../../../test_common.h"
#include <search.h>

void runSuccess() {
    if (!hcreate(anysize())) {return;}

    hdestroy();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    if (!hcreate(anysize())) {return;}
    
    hdestroy();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
