#include "../../../test_common.h"
#include <arpa/inet.h>
#include <stdint.h>

/*@
assigns \result;
*/
extern uint32_t anyuint32();

void runSuccess() {
    ntohl(5326);
    ntohl(0);
    ntohl(UINT32_MAX);
    ntohl(anyuint32());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    ntohl(5326);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
