#include "../../../test_common.h"
#include <signal.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct sigaction * anyaction();

void runSuccess() {
    sigaction(anyint(), anyaction(), anyaction());
}

void runSuccess1() {
    sigaction(anyint(), NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = sigaction(anyint(), anyaction(), anyaction());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
