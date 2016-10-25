#include "../../../test_common.h"
#include <pwd.h>

/*@
assigns \result;
*/
extern uid_t * anyuid();

void runSuccess() {
    getpwuid(anyuid());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    struct passwd * result;
    
    result = getpwuid(anyuid());
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
