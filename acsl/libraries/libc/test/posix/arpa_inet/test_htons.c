#include "../../../test_common.h"
#include <arpa/inet.h>
#include <stdint.h>

/*@
assigns \result;
*/
extern uint16_t anyuint16();

void runSuccess() {
    htons(5326);
    htons(0);
    htons(UINT16_MAX);
    htons(anyuint16());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    htons(5326);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
