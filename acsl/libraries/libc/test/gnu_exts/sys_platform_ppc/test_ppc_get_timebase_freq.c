#include "../../../test_common.h"
#include <sys/platform/ppc.h>

void runSuccess() {
    __ppc_get_timebase_freq();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    __ppc_get_timebase_freq();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
