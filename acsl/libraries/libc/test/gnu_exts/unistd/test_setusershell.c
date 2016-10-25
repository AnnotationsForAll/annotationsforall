#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    setusershell();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    setusershell();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
