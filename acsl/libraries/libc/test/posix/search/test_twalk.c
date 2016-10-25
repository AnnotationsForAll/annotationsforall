#include "../../../test_common.h"
#include <search.h>

/*@
assigns \result;
ensures \result != \null;
*/
extern int (*anyfunc())(const void *, int, int);

/*@
assigns \result;
ensures \valid((char*)\result);
*/
extern void* anyptr();

void runSuccess() {
    twalk(NULL, anyfunc());
}

void runSuccess1() {
    twalk(anyptr(), anyfunc());
}

void runFailure() {
    twalk(anyptr(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    twalk(NULL, anyfunc());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
