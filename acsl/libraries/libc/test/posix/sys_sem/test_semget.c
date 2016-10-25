#include "../../../test_common.h"
#include <sys/sem.h>

/*@
assigns \result;
*/
extern key_t anykey();

void runSuccess() {
    semget(anykey(), anyint(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = semget(anykey(), anyint(), anyint());
    //@ assert result >= -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
