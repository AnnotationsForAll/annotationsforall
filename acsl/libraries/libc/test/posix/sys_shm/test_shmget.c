#include "../../../test_common.h"
#include <sys/shm.h>

/*@
assigns \result;
*/
extern key_t anykey();

void runSuccess() {
    shmget(anykey(), anysize(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = shmget(anykey(), anysize(), anyint());
    //@ assert result >= -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
