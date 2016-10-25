#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    int err;
    getipnodebyname(anystring(), anyint(), anyint(), &err);
}

void runFailure() {
    int err;
    getipnodebyname(NULL, anyint(), anyint(), &err);
}

void runFailure1() {
    int err;
    getipnodebyname(anystring(), anyint(), anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    int err;
    struct hostent* result = getipnodebyname(anystring(), anyint(), anyint(), &err);
    //@ assert result == \null || \valid_read(result->h_name);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
