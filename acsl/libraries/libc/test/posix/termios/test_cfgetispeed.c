#include "../../../test_common.h"
#include <termios.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct termios * anytermios();

void runSuccess() {
    cfgetispeed(anytermios());
}

void runFailure() {
    cfgetispeed(NULL);
}

int f;
void testValues() {
    f = 2;
    speed_t result;
    
    cfgetispeed(anytermios());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
