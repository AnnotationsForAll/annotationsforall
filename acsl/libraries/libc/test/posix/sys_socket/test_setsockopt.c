#include "../../../test_common.h"
#include <sys/socket.h>

void runSuccess() {
    char sock[4];
    socklen_t socklen = sizeof(struct sockaddr);
    
    setsockopt(anyint(), anyint(), anyint(), sock, &socklen);
}

void runFailure2() {
    setsockopt(anyint(), anyint(), anyint(), NULL, NULL);
}

void runFailure1() {
    char sock[4];
    socklen_t socklen;
    
    setsockopt(anyint(), anyint(), anyint(), NULL, &socklen);
}

int f;
void testValues() {
    f = 2;
    int result;
    char sock[4];
    socklen_t socklen = sizeof(struct sockaddr);
    
    result = setsockopt(anyint(), anyint(), anyint(), sock, &socklen);
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
