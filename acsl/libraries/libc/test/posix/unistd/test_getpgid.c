#include "../../../test_common.h"
#include <unistd.h>

/*@
assigns \result;
*/
extern pid_t anypid();

void runSuccess() {
    getpgid(anypid());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    pid_t result;
    
    getpgid(anypid());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
