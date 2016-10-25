#include "../../../test_common.h"
#include <sys/profil.h>

void runSuccess() {
    struct prof buf[10];
    struct timeval tv;
    sprofil(buf, 10, &tv, anyuint());
}

void runSuccess1() {
    struct prof buf[10];
    struct timeval tv;
    sprofil(buf, 10, NULL, anyuint());
}

void runFailure() {
    struct prof buf[10];
    struct timeval tv;
    sprofil(NULL, 10, &tv, anyuint());
}

void runFailure1() {
    struct prof buf[10];
    struct timeval tv;
    sprofil(buf, 20, &tv, anyuint());
}

int f;
void testValues() {
    f = 2;
    
    struct prof buf[10];
    struct timeval tv;
    sprofil(buf, 10, &tv, anyuint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
