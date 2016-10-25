#include "../../../test_common.h"
#include <fmtmsg.h>

void runSuccess() {
    fmtmsg(MM_NULLMC, MM_NULLLBL, MM_NULLSEV, MM_NULLTXT, MM_NULLACT, MM_NULLTAG);
}

void runFailure() {
    const char *label, text, action, tag;
    fmtmsg(MM_NULLMC, label, MM_NULLSEV, text, action, tag);
}

int f;
void testValues() {
    f = 2;
    
    int result = fmtmsg(MM_NULLMC, MM_NULLLBL, MM_NULLSEV, MM_NULLTXT, MM_NULLACT, MM_NULLTAG);
    //@ assert result == MM_OK || result == MM_NOTOK || result == MM_NOMSG || result == MM_NOCON;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
