#include "../../../test_common.h"
#include <aio.h>

void runSuccess() {
    struct aiocb aio;
    aio_error(&aio);
}

void runFailure() {
    aio_error(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    struct aiocb aio;
    result = aio_error(&aio);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
