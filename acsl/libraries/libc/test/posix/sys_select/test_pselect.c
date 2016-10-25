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
extern struct timespec * anytime();

/*@
assigns \result;
ensures \valid(\result);
*/
extern sigset_t * anyset();

void runSuccess() {
    pselect(1, anyfd(), anyfd(), anyfd(), anytime(), anyset());
}

void runSuccess1() {
    pselect(1, anyfd(), anyfd(), anyfd(), anytime(), NULL);
}

void runSuccess2() {
    pselect(0, NULL, NULL, NULL, NULL, NULL);
}


void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = pselect(1, anyfd(), anyfd(), anyfd(), anytime(), anyset());
    //@ assert result >= -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
