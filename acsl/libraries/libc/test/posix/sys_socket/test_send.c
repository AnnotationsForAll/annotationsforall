#include "../../../test_common.h"
#include <sys/socket.h>

void runSuccess() {
    char buf[10];
    
    send(anyint(), buf, 10, anyint());
}

void runFailure() {
    send(anyint(), NULL, 10, anyint());
}

void runFailure1() {
    char buf[10];
    
    send(anyint(), buf, 20, anyint());
}

int f;
void testValues() {
    f = 2;
    ssize_t result;
    char buf[10];
    
    result = send(anyint(), buf, 10, anyint());
    //@ assert result >= (ssize_t)-1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
