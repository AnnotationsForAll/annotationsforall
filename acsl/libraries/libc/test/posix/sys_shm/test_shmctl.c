#include "../../../test_common.h"
#include <sys/shm.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct shmid_ds * anyds();

void runSuccess() {
    shmctl(anyint(), anyint(), anyds());
}

void runFailure() {
    shmctl(anyint(), anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = shmctl(anyint(), anyint(), anyds());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
