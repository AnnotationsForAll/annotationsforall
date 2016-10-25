#include "../../../test_common.h"
#include <sys/stat.h>

/*@
assigns \result;
*/
extern mode_t anymode();

void runSuccess() {
    fchmod(anyint(), anymode());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = fchmod(anyint(), anymode());
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
