#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    getpt();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    int result = getpt();
    //@ assert result >= -1;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
