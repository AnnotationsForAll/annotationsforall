#include "../../../test_common.h"
#include <aio.h>

void runSuccess() {
    struct aiocb aio;
    aio_fsync(anyint(), &aio);
}

void runFailure() {
    aio_fsync(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    struct aiocb aio;
    result = aio_fsync(anyint(), &aio);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
