#include "../../../test_common.h"
#include <shadow.h>

void runSuccess() {
    ulckpwdf();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    ulckpwdf();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
