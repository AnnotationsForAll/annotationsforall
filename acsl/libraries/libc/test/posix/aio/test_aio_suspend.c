#include "../../../test_common.h"
#include <aio.h>

void runSuccess() {
    struct aiocb * aio[1];
    aio[0] = NULL;
    struct timespec tm;
    
    aio_suspend(aio, 1, &tm);
}

void runSuccess1() {
    struct aiocb * aio[1];
    aio[0] = NULL;
    
    aio_suspend(aio, 1, NULL);
}

void runFailure() {
    struct timespec tm;
    
    aio_suspend(NULL, 1, &tm);
}

void runFailure1() {
    struct aiocb * aio[1];
    aio[0] = NULL;
    struct timespec tm;
    
    aio_suspend(aio, 4, &tm);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    struct aiocb * aio[1];
    aio[0] = NULL;
    struct timespec tm;
    
    result = aio_suspend(aio, 1, &tm);
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
