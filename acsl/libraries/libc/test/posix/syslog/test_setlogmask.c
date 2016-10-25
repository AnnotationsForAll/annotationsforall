#include "../../../test_common.h"
#include <syslog.h>

void runSuccess() {
    setlogmask(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    setlogmask(anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
