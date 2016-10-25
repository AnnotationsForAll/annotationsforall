#include "../../../test_common.h"
#include <sys/resource.h>

/*@
assigns \result;
*/
extern id_t anyid();

void runSuccess() {
    getpriority(PRIO_PROCESS, anyid());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = getpriority(PRIO_USER, anyid());
    //@ assert result == -1 || -NZERO <= result <= NZERO-1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
