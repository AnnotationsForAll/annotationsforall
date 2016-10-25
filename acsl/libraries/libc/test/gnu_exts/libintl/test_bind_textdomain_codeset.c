#include "../../../test_common.h"
#include <libintl.h>

void runSuccess() {
    bind_textdomain_codeset(anystring(), anystring());
}

void runSuccess1() {
    bind_textdomain_codeset(anystring(), NULL);
}

void runFailure() {
    bind_textdomain_codeset(NULL, anystring());
}

void runFailure1() {
    bind_textdomain_codeset(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    bind_textdomain_codeset(anystring(), anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
