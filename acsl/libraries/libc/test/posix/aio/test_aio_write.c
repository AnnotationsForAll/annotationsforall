#include "../../../test_common.h"
#include <aio.h>

void runSuccess() {
    struct aiocb aio;
    aio_write(&aio);
}

void runFailure() {
    aio_write(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    struct aiocb aio;
    result = aio_write(&aio);
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
