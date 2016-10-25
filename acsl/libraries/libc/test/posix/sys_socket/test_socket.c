#include "../../../test_common.h"
#include <sys/socket.h>

void runSuccess() {
    socket(anyint(), anyint(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    struct sockaddr sock;
    socklen_t socklen;
    
    result = socket(anyint(), anyint(), anyint());
    //@ assert result >= -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
