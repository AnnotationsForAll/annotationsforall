#include "../../../test_common.h"
#include <sys/socket.h>

void runSuccess() {
    sockatmark(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    struct sockaddr sock;
    socklen_t socklen;
    
    result = sockatmark(anyint());
    //@ assert -1 <= result <= 1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
