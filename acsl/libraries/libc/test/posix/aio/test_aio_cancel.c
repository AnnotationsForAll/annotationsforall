#include "../../../test_common.h"
#include <aio.h>

void runSuccess() {
    struct aiocb aio;
    aio_cancel(anyint(), &aio);
}

void runSuccess1() {
    aio_cancel(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    struct aiocb aio;
    result = aio_cancel(anyint(), &aio);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
