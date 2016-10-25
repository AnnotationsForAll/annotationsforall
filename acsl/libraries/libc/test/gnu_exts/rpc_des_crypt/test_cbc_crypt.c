#include "../../../test_common.h"
#include <rpc/des_crypt.h>

void runSuccess() {
    char key[8];
    char buf[16];
    char ivec[8];
    cbc_crypt(key, buf, 16, anyint(), ivec);
}

void runSuccess1() {
    char key[8];
    char buf[20];
    char ivec[8];
    cbc_crypt(key, buf, 16, anyint(), ivec);
}

void runFailure() {
    char key[8];
    char buf[16];
    char ivec[8];
    cbc_crypt(key, buf, 15, anyint(), ivec);
}

void runFailure1() {
    char key[8];
    char buf[16];
    char ivec[8];
    cbc_crypt(key, buf, 32, anyint(), ivec);
}

void runFailure2() {
    char key[4];
    char buf[16];
    char ivec[8];
    cbc_crypt(key, buf, 16, anyint(), ivec);
}

void runFailure3() {
    cbc_crypt(NULL, NULL, 0, anyint(), NULL);
}

void runFailure4() {
    char key[8];
    char buf[16];
    char ivec[4];
    cbc_crypt(key, buf, 16, anyint(), ivec);
}

int f;
void testValues() {
    f = 2;
    
    char key[8];
    char buf[16];
    char ivec[8];
    cbc_crypt(key, buf, 16, anyint(), ivec);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
