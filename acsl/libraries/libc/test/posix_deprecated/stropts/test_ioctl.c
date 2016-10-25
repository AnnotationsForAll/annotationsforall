#include "../../../test_common.h"
#include <stropts.h>

void runSuccess() {
    ioctl(anyint(), anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    ioctl(anyint(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
