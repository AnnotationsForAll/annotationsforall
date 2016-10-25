#include "../../../test_common.h"
#include <sys/socket.h>

void runSuccess() {
    struct sockaddr sock;
    socklen_t socklen;
    
    accept(anyint(), &sock, &socklen);
}

void runSuccess1() {
    accept(anyint(), NULL, NULL);
}

void runFailure() {
    struct sockaddr sock;
    socklen_t socklen;
    
    accept(anyint(), &sock, NULL);
}

void runFailure1() {
    struct sockaddr sock;
    socklen_t socklen;
    
    accept(anyint(), NULL, &socklen);
}

int f;
void testValues() {
    f = 2;
    int result;
    struct sockaddr sock;
    socklen_t socklen;
    
    result = accept(anyint(), &sock, &socklen);
    //@ assert result >= -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
