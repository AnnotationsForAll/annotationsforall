#include "../../../test_common.h"
#include <grp.h>

/*@
assigns \result;
*/
extern gid_t anygid();

void runSuccess() {
    getgrgid(anygid());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    struct group * result;
    
    result = getgrgid(anygid());
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
