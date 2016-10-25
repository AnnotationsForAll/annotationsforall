#include "../../../test_common.h"
#include <sgtty.h>

void runSuccess() {
    struct sgttyb p;
    stty(anyint(), &p);
}

void runFailure() {
    stty(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct sgttyb p;
    stty(anyint(), &p);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
