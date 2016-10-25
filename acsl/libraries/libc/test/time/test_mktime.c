#include "../../test_common.h"
#include <time.h>

/*@
assigns \result;
*/
extern time_t anytime();

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct tm * anytm();

void runSuccess() {
    mktime(anytm());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    mktime(anytm());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
