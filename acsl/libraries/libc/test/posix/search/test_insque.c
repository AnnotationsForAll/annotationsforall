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
    insque(anyque(), anyque());
}

void runSuccess1() {
    insque(anyque(), NULL);
}

void runFailure() {
    insque(NULL, anyque());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    insque(anyque(), anyque());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
