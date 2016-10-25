#include "../../../test_common.h"
#include <sys/socket.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct msghdr * anymsg();

void runSuccess() {
    sendmsg(anyint(), anymsg(), anyint());
}

void runFailure() {
    sendmsg(anyint(), NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    ssize_t result;
    
    result = sendmsg(anyint(), anymsg(), anyint());
    //@ assert result >= (ssize_t)-1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
