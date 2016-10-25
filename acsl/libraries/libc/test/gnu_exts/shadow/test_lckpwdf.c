#include "../../../test_common.h"
#include <shadow.h>

void runSuccess() {
    lckpwdf();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    lckpwdf();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
