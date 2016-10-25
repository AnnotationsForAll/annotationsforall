#include "../../../test_common.h"
#include <sys/socket.h>

void runSuccess() {
    struct sockaddr sock;
    socklen_t socklen;
    
    accept4(anyint(), &sock, &socklen, anyint());
}

void runSuccess1() {
    accept4(anyint(), NULL, NULL, anyint());
}

void runFailure() {
    struct sockaddr sock;
    socklen_t socklen;
    
    accept4(anyint(), &sock, NULL, anyint());
}

void runFailure1() {
    struct sockaddr sock;
    socklen_t socklen;
    
    accept4(anyint(), NULL, &socklen, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    struct sockaddr sock;
    socklen_t socklen;
    
    result = accept4(anyint(), &sock, &socklen, anyint());
    //@ assert result >= -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
