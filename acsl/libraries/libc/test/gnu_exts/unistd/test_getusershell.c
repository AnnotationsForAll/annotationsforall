#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    getusershell();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    getusershell();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
