#include "../../test_common.h"
#include <time.h>

/*@
assigns \result;
*/
extern time_t anytime();

time_t ptr;

void runSuccess() {
    ptr = anytime();
    gmtime(&ptr);
}

void runFailure() {
    gmtime(NULL);
}

int f;
void testValues() {
    f = 2;
    struct tm * result;
    
    ptr = anytime();
    result = gmtime(&ptr);
    //@ assert result==\null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}