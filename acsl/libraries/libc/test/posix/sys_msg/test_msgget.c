#include "../../../test_common.h"
#include <sys/msg.h>

/*@
assigns \result;
*/
extern key_t anykey();

void runSuccess() {
    msgget(anykey(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = msgget(anykey(), anyint());
    //@ assert result >= -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
