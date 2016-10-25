#include "../../../test_common.h"
#include <sys/wait.h>

void runSuccess() {
    int p = anyint();
    
    wait(&p);
}

void runSuccess1() {
    wait(NULL);
}

int f;
void testValues() {
    f = 2;
    pid_t result;
    
    int p = anyint();
    wait(&p);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
