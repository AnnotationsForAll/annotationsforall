#include "../../../test_common.h"
#include <sys/sem.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct sembuf * anysops();

void runSuccess() {
    semop(anyint(), anysops(), 1);
}

void runFailure() {
    semop(anyint(), NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = semop(anyint(), anysops(), 1);
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
