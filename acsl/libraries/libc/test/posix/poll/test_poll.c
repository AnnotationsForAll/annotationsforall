#include "../../../test_common.h"
#include <poll.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct pollfd * anyfds();

void runSuccess() {
    poll(anyfds(), 1, anyint());
}

void runFailure() {
    poll(NULL, 1, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = poll(anyfds(), 1, anyint());
    //@ assert result >= -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
