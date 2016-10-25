#include "../../../test_common.h"
#include <sys/fsuid.h>

void runSuccess() {
    setfsgid(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    setfsgid(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
