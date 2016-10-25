#include "../../../test_common.h"
#include <sys/sem.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct sembuf * anysops();

void runSuccess() {
    struct timespec t;
    semtimedop(anyint(), anysops(), 1, &t);
}

void runFailure() {
    struct timespec t;
    semtimedop(anyint(), NULL, 1, &t);
}

void runFailure1() {
    semtimedop(anyint(), anysops(), 1, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    struct timespec t;
    result = semtimedop(anyint(), anysops(), 1, &t);
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
