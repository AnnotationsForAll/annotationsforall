#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    fdatasync(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;

    fdatasync(anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
