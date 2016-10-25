#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    innetgr(anystring(), anystring(), anystring(), anystring());
}

void runSuccess1() {
    innetgr(NULL, NULL, NULL, NULL);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    innetgr(anystring(), anystring(), anystring(), anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
