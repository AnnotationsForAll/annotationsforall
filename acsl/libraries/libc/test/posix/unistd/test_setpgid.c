#include "../../../test_common.h"
#include <unistd.h>

/*@
assigns \result;
*/
extern pid_t anypid();

void runSuccess() {
    setpgid(anypid(), anypid());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = setpgid(anypid(), anypid());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
