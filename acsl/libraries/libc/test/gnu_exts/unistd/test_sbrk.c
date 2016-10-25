#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    sbrk(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    sbrk(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
