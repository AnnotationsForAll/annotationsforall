#include "../../../test_common.h"
#include <sys/platform/ppc.h>

void runSuccess() {
    __ppc_set_ppr_very_low();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    __ppc_set_ppr_very_low();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
