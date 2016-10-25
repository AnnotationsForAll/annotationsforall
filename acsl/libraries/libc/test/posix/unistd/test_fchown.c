#include "../../../test_common.h"
#include <unistd.h>

/*@
assigns \result;
*/
extern uid_t anyuid();

/*@
assigns \result;
*/
extern gid_t anygid();

void runSuccess() {
    fchown(anyint(), anyuid(), anygid());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = fchown(anyint(), anyuid(), anygid());
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
