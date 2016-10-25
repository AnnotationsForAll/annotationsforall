#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    fsync(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;

    fsync(anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
