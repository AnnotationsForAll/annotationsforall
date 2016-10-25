#include "../../../test_common.h"
#include <sys/socket.h>

void runSuccess() {
    int v[2];
    v[0] = anyint();
    v[1] = anyint();
    
    socketpair(anyint(), anyint(), anyint(), v);
}

void runFailure() {
    socketpair(anyint(), anyint(), anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    int v[2];
    v[0] = anyint();
    v[1] = anyint();
    
    result = socketpair(anyint(), anyint(), anyint(), v);
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
