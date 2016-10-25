#include "../../../test_common.h"
#include <arpa/inet.h>

void runSuccess() {
    char cp[] = "a";
    char buf[] = "b";
    inet_net_pton(AF_INET, cp, buf, 1);
}

void runFailure() {
    char buf[] = "b";
    inet_net_pton(AF_INET, NULL, buf, 1);
}

void runFailure1() {
    char cp[] = "a";
    inet_net_pton(AF_INET, cp, NULL, anyint());
}

void runFailure2() {
    char cp[] = "a";
    char buf[] = "b";
    inet_net_pton(AF_INET, cp, buf, 120);
}

int f;
void testValues() {
    f = 2;
    
    char cp[] = "a";
    char buf[] = "b";
    inet_net_pton(AF_INET, cp, buf, 1);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
