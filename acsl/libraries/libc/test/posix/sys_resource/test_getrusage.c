#include "../../../test_common.h"
#include <sys/resource.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct rusage * anylimit();

void runSuccess() {
    getrusage(anyint(), anylimit());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = getrusage(anyint(), anylimit());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
