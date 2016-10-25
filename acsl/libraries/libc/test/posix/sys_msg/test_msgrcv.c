#include "../../../test_common.h"
#include <sys/msg.h>

void runSuccess() {
    char buf[10];
    
    msgrcv(anyint(), buf, 10, anylongint(), anyint());
}

void runFailure() {
    msgrcv(anyint(), NULL, 10, anylongint(), anyint());
}

void runFailure1() {
    char buf[10];
    
    msgrcv(anyint(), buf, 20, anylongint(), anyint());
}

int f;
void testValues() {
    f = 2;
    ssize_t result;
    char buf[10];
    
    result = msgrcv(anyint(), buf, 10, anylongint(), anyint());
    //@ assert result >= -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
