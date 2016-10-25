#include "../../../test_common.h"
#include <shadow.h>

void runSuccess() {
    setspent();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    setspent();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
