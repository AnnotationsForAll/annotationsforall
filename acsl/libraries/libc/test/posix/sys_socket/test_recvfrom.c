#include "../../../test_common.h"
#include <sys/socket.h>

void runSuccess() {
    char buf[10];
    struct sockaddr sock;
    socklen_t socklen;
    
    recvfrom(anyint(), buf, 10, anyint(), &sock, &socklen);
}

void runSuccess1() {
    char buf[10];
    
    recvfrom(anyint(), buf, 10, anyint(), NULL, NULL);
}

void runFailure() {
    struct sockaddr sock;
    socklen_t socklen;
    
    recvfrom(anyint(), NULL, 10, anyint(), &sock, &socklen);
}

void runFailure1() {
    char buf[10];
    struct sockaddr sock;
    socklen_t socklen;
    
    recvfrom(anyint(), buf, 20, anyint(), &sock, &socklen);
}

void runFailure2() {
    char buf[10];
    struct sockaddr sock;
    socklen_t socklen;
    
    recvfrom(anyint(), buf, 10, anyint(), &sock, NULL);
}

int f;
void testValues() {
    f = 2;
    ssize_t result;
    char buf[10];
    struct sockaddr sock;
    socklen_t socklen;
    
    result = recvfrom(anyint(), buf, 10, anyint(), &sock, &socklen);
    //@ assert result >= (ssize_t)-1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
