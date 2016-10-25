#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    vhangup();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    vhangup();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
