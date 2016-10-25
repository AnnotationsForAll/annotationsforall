#include "../../../stdio_common.h"
#include <fmtmsg.h>

void runSuccess() {
    addseverity(anyint(), anystring());
}

void runSuccess1() {
    addseverity(anyint(), NULL);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    int result = addseverity(anyint(), anystring());
    //@ assert result == MM_OK || result == MM_NOTOK;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
