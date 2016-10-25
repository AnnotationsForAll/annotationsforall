#include "../../../test_common.h"
#include <sys/resource.h>

/*@
assigns \result;
*/
extern id_t anyid();

void runSuccess() {
    setpriority(PRIO_PROCESS, anyid(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = setpriority(PRIO_USER, anyid(), anyint());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
