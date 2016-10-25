#include "../../../test_common.h"
#include <libintl.h>

void runSuccess() {
    ngettext(anystring(), anystring(), anyint());
}

void runFailure() {
    ngettext(NULL, anystring(), anyint());
}

void runFailure1() {
    ngettext(anystring(), NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    ngettext(anystring(), anystring(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
