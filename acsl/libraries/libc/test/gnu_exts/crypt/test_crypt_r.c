#include "../../../test_common.h"
#include <crypt.h>

void runSuccess() {
    struct crypt_data data;
    data.initialized = 0;
    crypt_r(anystring(), anystring(), &data);
}

void runSuccess1() {
    struct crypt_data data;
    data.initialized = 0;
    crypt_r(anystring(), anystring(), &data);
    crypt_r(anystring(), anystring(), &data);
    data.initialized = 0;
    crypt_r(anystring(), anystring(), &data);
}

void runFailure() {
    struct crypt_data data;
    data.initialized = 0;
    crypt_r(NULL, anystring(), &data);
}

void runFailure1() {
    struct crypt_data data;
    data.initialized = 0;
    crypt_r(anystring(), NULL, &data);
}

void runFailure2() {
    struct crypt_data data;
    data.initialized = 0;
    crypt_r(anystring(), anystring(), NULL);
}

void runFailure3() {
    struct crypt_data data;
    crypt_r(anystring(), anystring(), &data);
}

int f;
void testValues() {
    f = 2;
    
    struct crypt_data data;
    data.initialized = 0;
    crypt_r(anystring(), anystring(), &data);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
