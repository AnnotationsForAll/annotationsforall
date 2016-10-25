#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    int err;
    struct hostent* hent = getipnodebyname(anystring(), anyint(), anyint(), &err);
    if (hent) {
        freehostent(hent);
    }
}

void runFailure() {
    freehostent(NULL);
}

void runFailure1() {
    int err;
    struct hostent* hent = getipnodebyname(anystring(), anyint(), anyint(), &err);
    if (hent) {
        freehostent(hent);
        freehostent(hent);
    }
}

int f;
void testValues() {
    f = 2;
    
    int err;
    struct hostent* hent = getipnodebyname(anystring(), anyint(), anyint(), &err);
    if (hent) {
        freehostent(hent);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
