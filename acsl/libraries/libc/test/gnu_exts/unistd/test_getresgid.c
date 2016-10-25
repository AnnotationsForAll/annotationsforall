#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    gid_t a, b, c;
    getresgid(&a, &b, &c);
}

void runFailure() {
    gid_t a, b, c;
    getresgid(NULL, &b, &c);
}

void runFailure1() {
    gid_t a, b, c;
    getresgid(&a, NULL, &c);
}

void runFailure2() {
    gid_t a, b, c;
    getresgid(&a, &b, NULL);
}

int f;
void testValues() {
    f = 2;
    
    gid_t a, b, c;
    getresgid(&a, &b, &c);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
