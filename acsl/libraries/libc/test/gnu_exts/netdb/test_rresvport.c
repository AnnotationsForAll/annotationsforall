#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    int port;
    rresvport(&port);
}

void runFailure() {
    rresvport(NULL);
}

int f;
void testValues() {
    f = 2;
    
    int port;
    rresvport(&port);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
