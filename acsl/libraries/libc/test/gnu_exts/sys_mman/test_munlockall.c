#include "../../../test_common.h"
#include <sys/mman.h>

void runSuccess() {
    munlockall();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    munlockall();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
