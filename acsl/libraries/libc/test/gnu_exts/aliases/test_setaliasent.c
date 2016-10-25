#include "../../../test_common.h"
#include <aliases.h>

void runSuccess() {
    setaliasent();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    setaliasent();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
