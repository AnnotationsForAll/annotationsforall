#include "../../../test_common.h"
#include <libintl.h>

void runSuccess() {
    dngettext(anystring(), anystring(), anystring(), anyint());
}

void runSuccess1() {
    dngettext(NULL, anystring(), anystring(), anyint());
}

void runFailure() {
    dngettext(anystring(), NULL, anystring(), anyint());
}

void runFailure1() {
    dngettext(anystring(), anystring(), NULL, anyint());
}

void runFailure2() {
    dngettext(NULL, NULL, anystring(), anyint());
}

void runFailure3() {
    dngettext(NULL, anystring(), NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    dngettext(anystring(), anystring(), anystring(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
