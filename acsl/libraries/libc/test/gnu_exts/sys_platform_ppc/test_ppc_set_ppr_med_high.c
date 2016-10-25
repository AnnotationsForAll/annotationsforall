#include "../../../test_common.h"
#include <sys/platform/ppc.h>

void runSuccess() {
    __ppc_set_ppr_med_high();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    __ppc_set_ppr_med_high();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
