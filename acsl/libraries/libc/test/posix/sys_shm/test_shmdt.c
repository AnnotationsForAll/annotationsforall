#include "../../../test_common.h"
#include <sys/shm.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern char * anyptr();

void runSuccess() {
    shmdt(anyptr());
}

void runFailure() {
    shmdt(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = shmdt(anyptr());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
