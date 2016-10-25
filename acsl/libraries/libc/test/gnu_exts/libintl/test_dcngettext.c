#include "../../../test_common.h"
#include <libintl.h>

void runSuccess() {
    dcngettext(anystring(), anystring(), anystring(), anyint(), anyint());
}

void runSuccess1() {
    dcngettext(NULL, anystring(), anystring(), anyint(), anyint());
}

void runFailure() {
    dcngettext(anystring(), NULL, anystring(), anyint(), anyint());
}

void runFailure1() {
    dcngettext(anystring(), anystring(), NULL, anyint(), anyint());
}

void runFailure2() {
    dcngettext(NULL, NULL, anystring(), anyint(), anyint());
}

void runFailure3() {
    dcngettext(NULL, anystring(), NULL, anyint(), anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    dcngettext(anystring(), anystring(), anystring(), anyint(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
