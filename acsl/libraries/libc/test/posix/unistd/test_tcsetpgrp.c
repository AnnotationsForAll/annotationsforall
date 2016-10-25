#include "../../../test_common.h"
#include <unistd.h>

/*@
assigns \result;
*/
extern pid_t anypid();

void runSuccess() {
    tcsetpgrp(anyint(), anypid());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = tcsetpgrp(anyint(), anypid());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
