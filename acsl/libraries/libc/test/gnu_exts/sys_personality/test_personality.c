#include "../../../test_common.h"
#include <sys/personality.h>

void runSuccess() {
    personality(anyulong());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    personality(anyulong());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
