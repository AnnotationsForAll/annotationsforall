#include "../../../test_common.h"
#include <termios.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct termios * anytermios();

void runSuccess() {
    tcgetattr(anyint(), anytermios());
}

void runFailure() {
    tcgetattr(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = tcgetattr(anyint(), anytermios());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
