#include "../../../test_common.h"
#include <sys/msg.h>

void runSuccess() {
    char buf[10];
    
    msgsnd(anyint(), buf, 10, anyint());
}

void runFailure() {
    msgsnd(anyint(), NULL, 10, anyint());
}

void runFailure1() {
    char buf[10];
    
    msgsnd(anyint(), buf, 20, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[10];
    
    result = msgsnd(anyint(), buf, 10, anyint());
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
