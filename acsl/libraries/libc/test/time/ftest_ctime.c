#include "../../test_common.h"
#include <time.h>

/*@
assigns \result;
*/
extern time_t anytime();

time_t ptr;

void runSuccess() {
    ptr = anytime();
    ctime(&ptr);
}

void runFailure() {
    ctime(NULL);
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    ptr = anytime();
    result = ctime(&ptr);
    //@ assert result==\null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}