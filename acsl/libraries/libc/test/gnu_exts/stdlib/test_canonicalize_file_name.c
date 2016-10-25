#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    canonicalize_file_name(anystring());
}

void runFailure() {
    canonicalize_file_name(NULL);
}

int f;
void testValues() {
    f = 2;
    
    canonicalize_file_name(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
