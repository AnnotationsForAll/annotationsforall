#include "../../../test_common.h"
#include <sys/mman.h>

void runSuccess() {
    mlockall(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    mlockall(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
