#include "../../../test_common.h"
#include <libintl.h>

void runSuccess() {
    dcgettext(anystring(), anystring(), anyint());
}

void runSuccess1() {
    dcgettext(NULL, anystring(), anyint());
}

void runFailure() {
    dcgettext(anystring(), NULL, anyint());
}

void runFailure1() {
    dcgettext(NULL, NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    dcgettext(anystring(), anystring(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
