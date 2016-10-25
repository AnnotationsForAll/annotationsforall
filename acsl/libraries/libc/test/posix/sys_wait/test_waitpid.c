#include "../../../test_common.h"
#include <sys/wait.h>

/*@
assigns \result;
*/
extern pid_t anypid();

void runSuccess() {
    int p = anyint();
    
    waitpid(anypid(), &p, anyint());
}

void runSuccess1() {
    waitpid(anypid(), NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    pid_t result;
    
    int p = anyint();
    waitpid(anypid(), &p, anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
