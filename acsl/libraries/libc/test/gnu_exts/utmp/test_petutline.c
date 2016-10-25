#include "../../../test_common.h"
#include <utmp.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct utmp * anyut();

void runSuccess() {
    pututline(anyut());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    struct utmp * result;
    
    result = pututline(anyut());
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
