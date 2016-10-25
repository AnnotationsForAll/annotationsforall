#include "../../../test_common.h"
#include <ttyent.h>

void runSuccess() {
    endttyent();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    endttyent();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
