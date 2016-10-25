#include "../../../test_common.h"
#include <aio.h>

void runSuccess() {
    struct aiocb aio;
    aio_return(&aio);
}

void runFailure() {
    aio_return(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    struct aiocb aio;
    result = aio_return(&aio);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
