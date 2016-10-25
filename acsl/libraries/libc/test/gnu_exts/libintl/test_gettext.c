#include "../../../test_common.h"
#include <libintl.h>

void runSuccess() {
    gettext(anystring());
}

void runFailure() {
    gettext(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    gettext(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
