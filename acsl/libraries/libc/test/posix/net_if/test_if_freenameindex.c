#include "../../../test_common.h"
#include <net/if.h>

void runSuccess() {
    struct if_nameindex * ni = if_nameindex();
    if (ni == NULL) {return;}

    if_freenameindex(ni);
}

void runFailure() {
    if_freenameindex(NULL);
}

int f;
void testValues() {
    f = 2;
    struct if_nameindex * ni = if_nameindex();
    if (ni == NULL) {return;}

    if_freenameindex(ni);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
