#include "../../../test_common.h"
#include <mcheck.h>

void runSuccess() {
    mcheck_check_all();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    mcheck_check_all();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
