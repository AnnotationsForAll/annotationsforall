#include "../../../test_common.h"
#include <sys/resource.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct rlimit * anylimit();

void runSuccess() {
    prlimit(anyint(), anyint(), anylimit(), anylimit());
}

void runSuccess1() {
    prlimit(anyint(), anyint(), anylimit(), NULL);
}

void runSuccess2() {
    prlimit(anyint(), anyint(), NULL, anylimit());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    prlimit(anyint(), anyint(), anylimit(), anylimit());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
