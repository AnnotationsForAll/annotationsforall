#include "../../../test_common.h"
#include <aio.h>

void runSuccess() {
    struct aiocb aio;
    aio_read(&aio);
}

void runFailure() {
    aio_read(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    struct aiocb aio;
    result = aio_read(&aio);
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
