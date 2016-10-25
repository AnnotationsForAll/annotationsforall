#include "../../../test_common.h"
#include <endian.h>

void runSuccess() {
    le16toh((uint16_t)anylonglong());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    uint16_t result;

    result = le16toh(0);
    //@ assert result == 0;

    result = le16toh(1);
    //@ assert BYTE_ORDER == BIG_ENDIAN ==> result == (1 << 8);
    //@ assert BYTE_ORDER == LITTLE_ENDIAN ==> result == 1;

    result = le16toh(42);
    //@ assert BYTE_ORDER == BIG_ENDIAN ==> result == (42 << 8);
    //@ assert BYTE_ORDER == LITTLE_ENDIAN ==> result == 42;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
