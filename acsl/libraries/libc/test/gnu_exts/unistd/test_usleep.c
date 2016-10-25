#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    usleep(anyuint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    usleep(anyuint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
