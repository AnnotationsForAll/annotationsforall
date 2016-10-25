#include "../../../test_common.h"
#include <termios.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct termios * anytermios();

void runSuccess() {
    cfgetospeed(anytermios());
}

void runFailure() {
    cfgetospeed(NULL);
}

int f;
void testValues() {
    f = 2;
    speed_t result;
    
    cfgetospeed(anytermios());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
