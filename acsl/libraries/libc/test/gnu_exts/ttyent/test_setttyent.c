#include "../../../test_common.h"
#include <ttyent.h>

void runSuccess() {
    setttyent();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    setttyent();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
