#include "../../../test_common.h"
#include <malloc.h>

void runSuccess() {
    malloc_get_state();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    malloc_get_state();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
