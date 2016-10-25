#include "../../../test_common.h"
#include <sys/socket.h>


void runSuccess() {
    char sock[5];
    socklen_t socklen = sizeof(struct sockaddr);

    getsockopt(anyint(), anyint(), anyint(), sock, &socklen);
}

void runFailure2() {
    char sock[5];
    socklen_t socklen = sizeof(struct sockaddr);

    getsockopt(anyint(), anyint(), anyint(), NULL, NULL);
}

void runFailure() {
    char sock[5];
    socklen_t socklen;
    
    getsockopt(anyint(), anyint(), anyint(), sock, NULL);
}

void runFailure1() {
    char sock[5];
    socklen_t socklen;
    
    getsockopt(anyint(), anyint(), anyint(), NULL, &socklen);
}

int f;
void testValues() {
    f = 2;
    int result;
    char sock[5];
    socklen_t socklen = sizeof(struct sockaddr);
    
    result = getsockopt(anyint(), anyint(), anyint(), sock, &socklen);
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
