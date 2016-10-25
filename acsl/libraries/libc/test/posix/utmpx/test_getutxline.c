#include "../../../test_common.h"
#include <utmpx.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct utmpx * anyutx();

void runSuccess() {
    getutxline(anyutx());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    struct utmpx * result;
    
    result = getutxline(anyutx());
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
