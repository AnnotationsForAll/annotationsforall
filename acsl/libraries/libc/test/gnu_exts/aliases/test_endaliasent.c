#include "../../../test_common.h"
#include <aliases.h>

void runSuccess() {
    endaliasent();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    endaliasent();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
