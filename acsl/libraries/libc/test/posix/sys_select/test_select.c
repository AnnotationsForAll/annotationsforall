#include "../../../test_common.h"
#include <sys/select.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern fd_set * anyfd();

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct timeval * anytime();

void runSuccess() {
    select(1, anyfd(), anyfd(), anyfd(), anytime());
}

void runSuccess1() {
    select(1, anyfd(), anyfd(), anyfd(), anytime());
}

void runSuccess2() {
    select(0, NULL, NULL, NULL, NULL);
}


void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = select(1, anyfd(), anyfd(), anyfd(), anytime());
    //@ assert result >= -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
