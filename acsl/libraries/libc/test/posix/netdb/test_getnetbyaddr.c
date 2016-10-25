#include "../../../test_common.h"
#include <netdb.h>
#include <stdint.h>

/*@
assigns \result;
*/
extern uint32_t anyuint32();

void runSuccess() {
    getnetbyaddr(anyuint32(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    struct netent * result;
    
    result = getnetbyaddr(anyuint32(), anyint());
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
