#include "../../../test_common.h"
#include <unistd.h>

/*@
assigns \result;
*/
extern uid_t anyuid();

void runSuccess() {
    seteuid(anyuid());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = seteuid(anyuid());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
