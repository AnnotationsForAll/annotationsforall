#include "../../../test_common.h"
#include <shadow.h>

void runSuccess() {
    endspent();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    endspent();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
