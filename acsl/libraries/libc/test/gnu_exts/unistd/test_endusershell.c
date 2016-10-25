#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    endusershell();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    endusershell();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
