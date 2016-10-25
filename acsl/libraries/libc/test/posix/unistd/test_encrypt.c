#include "../../../test_common.h"
#include <unistd.h>

/*@
assigns \nothing; //FIXME: assigns \result[0..63];
ensures \valid(\result+(0..63));
ensures \forall integer x; 0 <= x < 64 ==> \result[x] == 0 || \result[x] == 1;
*/
extern char* block();

void runSuccess() {
    encrypt(block(), 0);
    encrypt(block(), 1);
}

void runFailure() {
    encrypt(NULL, 1);
}

void runFailure1() {
    encrypt(block(), anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    encrypt(block(), 1);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
