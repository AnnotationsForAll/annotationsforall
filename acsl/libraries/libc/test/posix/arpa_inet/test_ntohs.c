#include "../../../test_common.h"
#include <arpa/inet.h>
#include <stdint.h>

/*@
assigns \result;
*/
extern uint16_t anyuint16();

void runSuccess() {
    ntohs(5326);
    ntohs(0);
    ntohs(UINT16_MAX);
    ntohs(anyuint16());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    ntohs(5326);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
