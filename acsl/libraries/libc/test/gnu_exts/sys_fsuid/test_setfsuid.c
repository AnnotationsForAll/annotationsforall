#include "../../../test_common.h"
#include <sys/fsuid.h>

void runSuccess() {
    setfsuid(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    setfsuid(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
