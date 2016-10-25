#include "../../../test_common.h"
#include <arpa/inet.h>

void runSuccess() {
    char cp[] = "a";
    char buf[] = "b";
    inet_net_ntop(AF_INET, cp, 8, buf, 1);
}

void runSuccess1() {
    char cp[] = "a";
    char buf[] = "b";
    inet_net_ntop(AF_INET, cp, 4, buf, 1);
}

void runSuccess2() {
    char cp[] = "aa";
    char buf[] = "bb";
    inet_net_ntop(AF_INET, cp, 14, buf, 2);
}

void runFailure() {
    char buf[] = "b";
    inet_net_ntop(AF_INET, NULL, anyint(), buf, 1);
}

void runFailure1() {
    char cp[] = "a";
    inet_net_ntop(AF_INET, cp, 8, NULL, anyint());
}

void runFailure2() {
     char cp[] = "a";
     char buf[] = "b";
     inet_net_ntop(AF_INET, cp, 8, buf, 40);
}

void runFailure3() {
     char cp[] = "a";
     char buf[] = "b";
     inet_net_ntop(AF_INET, cp, 64, buf, 1);
}

int f;
void testValues() {
    f = 2;
    
    char cp[] = "a";
    char buf[] = "b";
    char* result = inet_net_ntop(AF_INET, cp, 8, buf, 1);
    //@ assert result != \null ==> result == buf;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
