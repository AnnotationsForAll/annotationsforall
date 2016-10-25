#include "../../../test_common.h"
#include <rpc/des_crypt.h>

void runSuccess() {
    char key[8];
    char buf[16];
    ecb_crypt(key, buf, 16, anyint());
}

void runSuccess1() {
    char key[8];
    char buf[20];
    ecb_crypt(key, buf, 16, anyint());
}

void runFailure() {
    char key[8];
    char buf[16];
    ecb_crypt(key, buf, 15, anyint());
}

void runFailure1() {
    char key[8];
    char buf[16];
    ecb_crypt(key, buf, 32, anyint());
}

void runFailure2() {
    char key[4];
    char buf[16];
    ecb_crypt(key, buf, 16, anyint());
}

void runFailure3() {
    ecb_crypt(NULL, NULL, 0, anyint());
}

int f;
void testValues() {
    f = 2;
    
    char key[8];
    char buf[16];
    ecb_crypt(key, buf, 16, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
