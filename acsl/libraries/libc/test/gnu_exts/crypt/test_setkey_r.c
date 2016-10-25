#include "../../../test_common.h"
#include <crypt.h>

void runSuccess() {
    struct crypt_data data;
    data.initialized = 0;
    char buf[64];
    setkey_r(buf, &data);
}

void runSuccess1() {
    struct crypt_data data;
    data.initialized = 0;
    char buf[100];
    setkey_r(buf, &data);
}

void runSuccess2() {
    struct crypt_data data;
    data.initialized = 0;
    char buf[64];
    setkey_r(buf, &data);
    setkey_r(buf, &data);
    data.initialized = 0;
    setkey_r(buf, &data);
}

void runFailure() {
    struct crypt_data data;
    data.initialized = 0;
    char buf[64];
    setkey_r(NULL, &data);
}

void runFailure1() {
    struct crypt_data data;
    data.initialized = 0;
    char buf[64];
    setkey_r(buf, NULL);
}

void runFailure2() {
    struct crypt_data data;
    data.initialized = 0;
    char buf[63];
    setkey_r(buf, &data);
}

void runFailure3() {
    struct crypt_data data;
    char buf[64];
    setkey_r(buf, &data);
}

int f;
void testValues() {
    f = 2;
    
    struct crypt_data data;
    data.initialized = 0;
    char buf[64];
    setkey_r(buf, &data);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
