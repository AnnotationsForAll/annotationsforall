#include "../../test_common.h"
#include <time.h>

/*@
assigns \result;
*/
extern time_t anytime();

void runSuccess() {
    difftime(anytime(), anytime());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    difftime(anytime(), anytime());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
