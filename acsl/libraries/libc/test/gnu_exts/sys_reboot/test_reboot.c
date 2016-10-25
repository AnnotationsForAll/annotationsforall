#include "../../../test_common.h"
#include <sys/reboot.h>

void runSuccess() {
    reboot(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    reboot(RB_DISABLE_CAD);
    reboot(RB_POWER_OFF);
    reboot(RB_ENABLE_CAD);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
