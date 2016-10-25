#include "../../../test_common.h"
#include <rpc/des_crypt.h>

void runSuccess() {
    char key[8];
    des_setparity(key);
}

void runSuccess1() {
    char key[12];
    des_setparity(key);
}

void runFailure() {
    des_setparity(NULL);
}

void runFailure1() {
    char key[4];
    des_setparity(key);
}

int f;
void testValues() {
    f = 2;
    
    char key[8];
    des_setparity(key);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
