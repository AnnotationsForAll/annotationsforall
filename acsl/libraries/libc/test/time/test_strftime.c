#include "../../test_common.h"
#include <time.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct tm * anytm();

void runSuccess() {
    char buf[] = "Buffer hopefully long enough to store a whole time format string";
    
    strftime(buf, 30, "!%c!", anytm());
}

void runFailure() {
    char buf[] = "Buffer hopefully long enough to store a whole time format string";
    
    strftime(NULL, 30, "!%c!", anytm());
}

int f;
void testValues() {
    f = 2;
    size_t result;
    char buf[] = "Buffer hopefully long enough to store a whole time format string";
    
    result = strftime(buf, 30, "%c", anytm());
    //@ assert result != 0 ==> \valid(buf+(0..29));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
