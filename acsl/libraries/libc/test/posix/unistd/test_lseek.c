#include "../../../test_common.h"
#include <unistd.h>

/*@
assigns \result;
*/
extern off_t anyoff();

void runSuccess() {
    lseek(anyint(), anyoff(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = lseek(anyint(), anyoff(), anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
