#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    ualarm(anyuint(), anyuint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    ualarm(anyuint(), anyuint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
