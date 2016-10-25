#include "../../../test_common.h"
#include <arpa/inet.h>

void runSuccess() {
    inet_network(anystring());
}

void runFailure() {
    inet_network(NULL);
}

int f;
void testValues() {
    f = 2;
    
    inet_network(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
