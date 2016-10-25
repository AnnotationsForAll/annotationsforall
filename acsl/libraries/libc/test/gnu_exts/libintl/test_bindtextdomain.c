#include "../../../test_common.h"
#include <libintl.h>

void runSuccess() {
    bindtextdomain(anystring(), anystring());
}

void runSuccess1() {
    bindtextdomain(anystring(), NULL);
}

void runFailure() {
    bindtextdomain(NULL, anystring());
}

void runFailure1() {
    bindtextdomain(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    bindtextdomain(anystring(), anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
