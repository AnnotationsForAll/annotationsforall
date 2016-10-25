#include "../../../test_common.h"
#include <arpa/inet.h>
#include <stdint.h>

/*@
assigns \result;
*/
extern uint32_t anyuint32();

void runSuccess() {
    htonl(5326);
    htonl(0);
    htonl(UINT32_MAX);
    htonl(anyuint32());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    htonl(5326);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
