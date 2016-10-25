#include "../../../test_common.h"
#include <sys/socket.h>

void runSuccess() {
    struct sockaddr sock;
    socklen_t socklen = sizeof(struct sockaddr);
    
    getpeername(anyint(), &sock, &socklen);
}

void runFailure2() {
    getpeername(anyint(), NULL, NULL);
}

void runFailure() {
    struct sockaddr sock;
    socklen_t socklen;
    
    getpeername(anyint(), &sock, NULL);
}

void runFailure1() {
    struct sockaddr sock;
    socklen_t socklen;
    
    getpeername(anyint(), NULL, &socklen);
}

int f;
void testValues() {
    f = 2;
    int result;
    struct sockaddr sock;
    socklen_t socklen = sizeof(struct sockaddr);
    
    result = getpeername(anyint(), &sock, &socklen);
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
