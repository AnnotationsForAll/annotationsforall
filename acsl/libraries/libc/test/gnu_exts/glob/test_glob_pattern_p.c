#include "../../../test_common.h"
#include <glob.h>

void runSuccess() {
    glob_pattern_p(anystring(), anyint());
}

void runFailure() {
    glob_pattern_p(NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    
    glob_pattern_p(anystring(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
