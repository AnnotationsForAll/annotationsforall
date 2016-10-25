#include "../../../test_common.h"
#include <utmp.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct utmp * anyut();

void runSuccess() {
    getutid(anyut());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    struct utmp * result;
    
    result = getutid(anyut());
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
