#include "../../../test_common.h"
#include <aio.h>

void runSuccess() {
    struct aioinit aio;
    aio_init(&aio);
}

void runFailure() {
    aio_init(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    struct aioinit aio;
    aio_init(&aio);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
