#include "../../../test_common.h"
#include <sys/vlimit.h>

void runSuccess() {
    vlimit(LIM_CPU, anyint());
}

void runFailure() {
    vlimit(anyint(), anyint());
}

int f;
void testValues() {
    f = 2;
    
    vlimit(LIM_CORE, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
