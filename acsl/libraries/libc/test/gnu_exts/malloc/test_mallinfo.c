#include "../../../test_common.h"
#include <malloc.h>

void runSuccess() {
    mallinfo();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    mallinfo();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
