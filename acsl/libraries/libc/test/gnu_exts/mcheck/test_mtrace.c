#include "../../../test_common.h"
#include <mcheck.h>

void runSuccess() {
    mtrace();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    mtrace();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
