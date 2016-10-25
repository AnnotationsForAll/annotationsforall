#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    int port;
    rresvport_af(&port, anyint());
}

void runFailure() {
    rresvport_af(NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    
    int port;
    rresvport_af(&port, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
