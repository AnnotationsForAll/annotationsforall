#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    gethostbyname2(anystring(), anyint());
}

void runFailure() {
    gethostbyname2(NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    
    gethostbyname2(anystring(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
