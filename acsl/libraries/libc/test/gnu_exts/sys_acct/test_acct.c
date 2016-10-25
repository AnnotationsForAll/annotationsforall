#include "../../../test_common.h"
#include <sys/acct.h>

void runSuccess() {
    acct(anystring());
}

void runSuccess1() {
    acct(NULL);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    acct(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
