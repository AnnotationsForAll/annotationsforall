#include "../../../test_common.h"
#include <sys/socket.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct sockaddr * anysock();

void runSuccess() {
    connect(anyint(), anysock(), sizeof(struct sockaddr));
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    struct sockaddr sock;
    socklen_t socklen;
    
    result = connect(anyint(), anysock(), sizeof(struct sockaddr));
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
