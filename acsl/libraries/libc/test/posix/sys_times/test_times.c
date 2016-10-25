#include "../../../test_common.h"
#include <sys/times.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct tms * anytms();

void runSuccess() {
    times(anytms());
}

void runFailure() {
    times(NULL);
}

int f;
void testValues() {
    f = 2;
    clock_t result;
    
    times(anytms());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
