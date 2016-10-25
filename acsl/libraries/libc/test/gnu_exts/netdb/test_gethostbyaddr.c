#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    char buf[] = "s";
    gethostbyaddr(buf, 1, anyint());
}

void runSuccess1() {
    char buf[] = "s";
    gethostbyaddr(buf, 0, anyint());
}

void runFailure() {
    gethostbyaddr(NULL, anyint(), anyint());
}

void runFailure1() {
    char buf[] = "s";
    gethostbyaddr(buf, 50, anyint());
}

int f;
void testValues() {
    f = 2;
    
    char buf[] = "s";
    gethostbyaddr(buf, 1, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
