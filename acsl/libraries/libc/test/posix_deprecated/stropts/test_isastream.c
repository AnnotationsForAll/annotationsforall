#include "../../../test_common.h"
#include <stropts.h>

void runSuccess() {
    isastream(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    int result = isastream(anyint());
    //@ assert -1 <= result <= 1;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
