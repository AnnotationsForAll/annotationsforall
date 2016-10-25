#include "../../../test_common.h"
#include <netinet/in.h>

void runSuccess() {
    struct sockaddr_in addr;
    bindresvport(anyint(), &addr);
}

void runSuccess1() {
    bindresvport(anyint(), NULL);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    struct sockaddr_in addr;
    int result = bindresvport(anyint(), &addr);
    //@ assert result == 0 ==> addr.sin_port < 1024;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
