#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    uid_t a, b, c;
    getresuid(&a, &b, &c);
}

void runFailure() {
    uid_t a, b, c;
    getresuid(NULL, &b, &c);
}

void runFailure1() {
    uid_t a, b, c;
    getresuid(&a, NULL, &c);
}

void runFailure2() {
    uid_t a, b, c;
    getresuid(&a, &b, NULL);
}

int f;
void testValues() {
    f = 2;
    
    uid_t a, b, c;
    getresuid(&a, &b, &c);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
