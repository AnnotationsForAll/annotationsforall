#include "../../../test_common.h"
#include <shadow.h>

void runSuccess() {
    getspent();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    struct spwd * result = getspent();
    //@ assert result != \null ==> \valid_read(result->sp_namp);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
