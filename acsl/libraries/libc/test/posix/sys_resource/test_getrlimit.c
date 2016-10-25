#include "../../../test_common.h"
#include <sys/resource.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct rlimit * anylimit();

void runSuccess() {
    getrlimit(anyint(), anylimit());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = getrlimit(anyint(), anylimit());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
