#include "../../../test_common.h"
#include <sys/platform/ppc.h>

void runSuccess() {
    __ppc_mdoom();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    __ppc_mdoom();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
