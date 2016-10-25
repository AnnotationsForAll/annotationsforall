#include "../../../test_common.h"
#include <unistd.h>

/*@
assigns \result;
*/
extern off_t anyoff();

void runSuccess() {
    lockf(anyint(), anyint(), anyoff());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = lockf(anyint(), anyint(), anyoff());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
