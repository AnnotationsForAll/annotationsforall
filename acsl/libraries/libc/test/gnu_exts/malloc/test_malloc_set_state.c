#include "../../../test_common.h"
#include <malloc.h>

void runSuccess() {
    void* state = malloc_get_state();
    if (state) {
        malloc_set_state(state);
    }
}

void runFailure() {
    malloc_set_state(NULL);
}

int f;
void testValues() {
    f = 2;
    
    void* state = malloc_get_state();
    if (state) {
        malloc_set_state(state);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
