#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    char buf[10];
    setdomainname(buf, 10);
}

void runFailure() {
    char buf[10];
    setdomainname(NULL, 10);
}

void runFailure1() {
    char buf[10];
    setdomainname(buf, 20);
}

int f;
void testValues() {
    f = 2;
    
    char buf[10];
    setdomainname(buf, 10);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
