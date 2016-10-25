//OPTIONS: -wp-model Typed+cast

#include "../../../test_common.h"
#include <search.h>

struct {
    struct myque *next;
    struct myque *prev;
} myque;

/*@
assigns \result;
ensures \valid(\result);
ensures \valid((char*)\result);
*/
extern struct myque * anyque();

void runSuccess() {
    remque(anyque());
}

void runFailure() {
    remque(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    remque(anyque());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
