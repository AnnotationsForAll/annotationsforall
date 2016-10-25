#include "../../../test_common.h"
#include <unistd.h>

/*@
assigns \result;
*/
extern off_t anyoff();

void runSuccess() {
    ftruncate(anyint(), anyoff());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = ftruncate(anyint(), anyoff());
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
