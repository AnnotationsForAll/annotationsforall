#include "../../../test_common.h"
#include <netinet/in.h>

void runSuccess() {
    struct sockaddr_in6 addr;
    bindresvport6(anyint(), &addr);
}

void runSuccess1() {
    bindresvport6(anyint(), NULL);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    struct sockaddr_in6 addr;
    int result = bindresvport6(anyint(), &addr);
    //@ assert result == 0 ==> addr.sin6_port < 1024;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
