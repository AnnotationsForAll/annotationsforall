#include "../../../test_common.h"
#include <unistd.h>

/*@
assigns \result;
*/
extern gid_t anygid();

void runSuccess() {
    setregid(anygid(), anygid());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = setregid(anygid(), anygid());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
