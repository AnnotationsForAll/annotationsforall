#include "../../../test_common.h"
#include <sys/file.h>

void runSuccess() {
    flock(anyint(), anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    flock(anyint(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
