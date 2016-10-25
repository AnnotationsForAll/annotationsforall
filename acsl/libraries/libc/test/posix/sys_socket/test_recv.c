#include "../../../test_common.h"
#include <sys/socket.h>

void runSuccess() {
    char buf[10];
    
    recv(anyint(), buf, 10, anyint());
}

void runFailure() {
    recv(anyint(), NULL, 10, anyint());
}

void runFailure1() {
    char buf[10];
    
    recv(anyint(), buf, 20, anyint());
}

int f;
void testValues() {
    f = 2;
    ssize_t result;
    char buf[10];
    
    result = recv(anyint(), buf, 10, anyint());
    //@ assert result >= (ssize_t)-1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
