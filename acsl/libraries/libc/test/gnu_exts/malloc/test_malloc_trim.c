#include "../../../test_common.h"
#include <malloc.h>

void runSuccess() {
    malloc_trim(anysize());
}

void runSuccess1() {
    malloc_trim(0);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    malloc_trim(anysize());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
