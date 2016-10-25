#include "../../../test_common.h"
#include <sys/uio.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct iovec * anyiov();

void runSuccess() {
    preadv(anyint(), anyiov(), 1, anyint());
}

void runFailure() {
    preadv(anyint(), NULL, 1, anyint());
}

int f;
void testValues() {
    f = 2;
    ssize_t result;
    
    result = preadv(anyint(), anyiov(), 1, anyint());
    //@ assert result >= -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
