#include "../../../test_common.h"
#include <shadow.h>

void runSuccess() {
    sgetspent(anystring());
}

void runFailure() {
    sgetspent(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct spwd * result = sgetspent(anystring());
    //@ assert result != \null ==> \valid_read(result->sp_namp);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
