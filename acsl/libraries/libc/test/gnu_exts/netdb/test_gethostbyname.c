#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    gethostbyname(anystring());
}

void runFailure() {
    gethostbyname(NULL);
}

int f;
void testValues() {
    f = 2;
    
    gethostbyname(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
