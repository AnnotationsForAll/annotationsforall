#include "../../../test_common.h"
#include <sys/auxv.h>

void runSuccess() {
    getauxval(anylongint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    getauxval(anylongint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
