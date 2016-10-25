#include "../../../test_common.h"
#include <shadow.h>

void runSuccess() {
    getspnam(anystring());
}

void runFailure() {
    getspnam(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct spwd * result = getspnam(anystring());
    //@ assert result != \null ==> \valid_read(result->sp_namp);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
