#include "../../../test_common.h"
#include <syslog.h>

void runSuccess() {
    closelog();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    closelog();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
