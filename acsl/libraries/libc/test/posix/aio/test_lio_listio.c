#include "../../../test_common.h"
#include <aio.h>

void runSuccess() {
    struct aiocb * aio[1];
    aio[0] = NULL;
    struct sigevent sig;
    
    lio_listio(anyint(), aio, 1, &sig);
}

void runFailure() {
    struct sigevent sig;
    
    lio_listio(anyint(), NULL, 1, &sig);
}

void runFailure1() {
    struct aiocb * aio[1];
    aio[0] = NULL;
    struct sigevent sig;
    
    lio_listio(anyint(), aio, 4, &sig);
}

void runFailure2() {
    struct aiocb * aio[1];
    aio[0] = NULL;
    
    lio_listio(anyint(), aio, 1, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    struct aiocb * aio[1];
    aio[0] = NULL;
    struct sigevent sig;
    
    result = lio_listio(anyint(), aio, 1, &sig);
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
