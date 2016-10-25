#include "../../../test_common.h"
#include <sys/msg.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct msqid_ds * anybuf();

void runSuccess() {
    msgctl(anyint(), anyint(), anybuf());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = msgctl(anyint(), anyint(), anybuf());
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
