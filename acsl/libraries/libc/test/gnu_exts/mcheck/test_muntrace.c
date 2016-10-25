#include "../../../test_common.h"
#include <mcheck.h>

void runSuccess() {
    muntrace();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    muntrace();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
