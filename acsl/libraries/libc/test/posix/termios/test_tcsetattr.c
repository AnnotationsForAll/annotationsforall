#include "../../../test_common.h"
#include <termios.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct termios * anytermios();

void runSuccess() {
    tcsetattr(anyint(), anyint(), anytermios());
}

void runFailure() {
    tcsetattr(anyint(), anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = tcsetattr(anyint(), anyint(), anytermios());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
