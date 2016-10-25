#include "../../../test_common.h"
#include <sgtty.h>

void runSuccess() {
    struct sgttyb p;
    gtty(anyint(), &p);
}

void runFailure() {
    gtty(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct sgttyb p;
    gtty(anyint(), &p);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
