#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    unsigned short buf[10];
    profil(buf, 10, anysize(), anyuint());
}

void runFailure() {
    unsigned short buf[10];
    profil(NULL, 10, anysize(), anyuint());
}

void runFailure1() {
    unsigned short buf[10];
    profil(buf, 20, anysize(), anyuint());
}

int f;
void testValues() {
    f = 2;
    
    unsigned short buf[10];
    profil(buf, 10, anysize(), anyuint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
