#include "../../../test_common.h"
#include <crypt.h>

void runSuccess() {
    struct crypt_data data;
    data.initialized = 0;
    char buf[64];
    encrypt_r(buf, 0, &data);
}

void runSuccess1() {
    struct crypt_data data;
    data.initialized = 0;
    char buf[64];
    encrypt_r(buf, 1, &data);
}

void runSuccess2() {
    struct crypt_data data;
    data.initialized = 0;
    char buf[100];
    encrypt_r(buf, 0, &data);
}

void runSuccess3() {
    struct crypt_data data;
    data.initialized = 0;
    char buf[64];
    encrypt_r(buf, 1, &data);
    encrypt_r(buf, 0, &data);
    data.initialized = 0;
    encrypt_r(buf, 1, &data);
}

void runFailure() {
    struct crypt_data data;
    data.initialized = 0;
    char buf[64];
    encrypt_r(NULL, 0, &data);
}

void runFailure1() {
    struct crypt_data data;
    data.initialized = 0;
    char buf[64];
    encrypt_r(buf, 1, NULL);
}

void runFailure2() {
    struct crypt_data data;
    data.initialized = 0;
    char buf[63];
    encrypt_r(buf, 0, &data);
}

void runFailure3() {
    struct crypt_data data;
    char buf[64];
    encrypt_r(buf, 1, &data);
}

void runFailure4() {
    struct crypt_data data;
    data.initialized = 0;
    char buf[64];
    encrypt_r(buf, anyint(), &data);
}

int f;
void testValues() {
    f = 2;
    
    struct crypt_data data;
    data.initialized = 0;
    char buf[64];
    encrypt_r(buf, 0, &data);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
