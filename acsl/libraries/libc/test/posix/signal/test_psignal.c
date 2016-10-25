#include "../../../test_common.h"
#include <signal.h>

void runSuccess() {
    psignal(anyint(), NULL);
}

void runSuccess1() {
    char buf[] = "head";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    psignal(anyint(), buf);
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    psignal(anyint(), NULL);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
