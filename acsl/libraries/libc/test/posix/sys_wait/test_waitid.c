#include "../../../test_common.h"
#include <sys/wait.h>

/*@
assigns \result;
*/
extern id_t anyid();

/*@
assigns \result;
*/
extern idtype_t anyidt();

/*@
assigns \result;
ensures \valid(\result);
*/
extern siginfo_t * anysig();

void runSuccess() {
    waitid(anyidt(), anyid(), anysig(), anyint());
}

void runFailure() {
    waitid(anyidt(), anyid(), NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = waitid(anyidt(), anyid(), anysig(), anyint());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
