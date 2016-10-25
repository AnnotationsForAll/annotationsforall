#include "../../../test_common.h"
#include <libintl.h>

void runSuccess() {
    textdomain(anystring());
}

void runSuccess1() {
    textdomain(NULL);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    int result;
    
    textdomain(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
