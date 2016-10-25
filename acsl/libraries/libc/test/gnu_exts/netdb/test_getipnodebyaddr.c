#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    char buf[10];
    int err;
    getipnodebyaddr(buf, 10, anyint(), &err);
}

void runFailure() {
    char buf[10];
    int err;
    getipnodebyaddr(NULL, anyint(), anyint(), &err);
}

void runFailure1() {
    char buf[10];
    int err;
    getipnodebyaddr(buf, 10, anyint(), NULL);
}

void runFailure2() {
    char buf[10];
    int err;
    getipnodebyaddr(buf, 20, anyint(), &err);
}

int f;
void testValues() {
    f = 2;
    
    char buf[10];
    int err;
    struct hostent* result = getipnodebyaddr(buf, 10, anyint(), &err);
    //@ assert result == \null || \valid_read(result->h_name);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
