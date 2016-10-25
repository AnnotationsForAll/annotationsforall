#include "../../../test_common.h"
#include <sys/stat.h>

/*@
assigns \result;
*/
extern mode_t anymode();

void runSuccess() {
    umask(anymode());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    umask(anymode());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
