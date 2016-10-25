#include "../../../test_common.h"
#include <sys/socket.h>

void runSuccess() {
    char buf[10];
    struct sockaddr sock;
    socklen_t socklen;
    
    sendto(anyint(), buf, 10, anyint(), &sock, &socklen);
}

void runFailure() {
    struct sockaddr sock;
    socklen_t socklen;
    
    sendto(anyint(), NULL, 10, anyint(), &sock, &socklen);
}

void runFailure1() {
    char buf[10];
    struct sockaddr sock;
    socklen_t socklen;
    
    sendto(anyint(), buf, 20, anyint(), &sock, &socklen);
}

void runFailure2() {
    char buf[10];
    
    sendto(anyint(), buf, 10, anyint(), NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    ssize_t result;
    char buf[10];
    struct sockaddr sock;
    socklen_t socklen;
    
    result = sendto(anyint(), buf, 10, anyint(), &sock, &socklen);
    //@ assert result >= (ssize_t)-1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
