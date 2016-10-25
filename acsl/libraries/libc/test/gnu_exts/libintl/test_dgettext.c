#include "../../../test_common.h"
#include <libintl.h>

void runSuccess() {
    dgettext(anystring(), anystring());
}

void runSuccess1() {
    dgettext(NULL, anystring());
}

void runFailure() {
    dgettext(anystring(), NULL);
}

void runFailure1() {
    dgettext(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    dgettext(anystring(), anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
