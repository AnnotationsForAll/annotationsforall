#include "../../../test_common.h"
#include <sys/uio.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct iovec * anyiov();

void runSuccess() {
    pwritev(anyint(), anyiov(), 1, anyint());
}

void runFailure() {
    pwritev(anyint(), NULL, 1, anyint());
}

int f;
void testValues() {
    f = 2;
    ssize_t result;
    
    result = pwritev(anyint(), anyiov(), 1, anyint());
    //@ assert result >= -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
