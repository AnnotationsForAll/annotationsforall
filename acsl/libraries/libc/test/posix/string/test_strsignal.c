#include "../../../test_common.h"
#include <string.h>
#include <signal.h>

void runSuccess() {
    strsignal(SIGINT);
    strsignal(SIGTTOU);
    strsignal(SIGFPE);
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    result = strsignal(SIGURG);
    //@ assert \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
