#include "../../../test_common.h"
#include <sys/shm.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern char * anyptr();

void runSuccess() {
    shmat(anyint(), anyptr(), anyint());
}

void runSuccess1() {
    shmat(anyint(), NULL, anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    result = shmat(anyint(), NULL, anyint());
    //@ assert result == (char*)-1 || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
