#include "../../../test_common.h"
#include <endian.h>

void runSuccess() {
    le32toh((uint32_t)anylonglong());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    uint32_t result;

    result = le32toh(0);
    //@ assert result == 0;

    result = le32toh(1);
    //@ assert BYTE_ORDER == BIG_ENDIAN ==> result == (1LL << 24);
    //@ assert BYTE_ORDER == LITTLE_ENDIAN ==> result == 1;

    result = le32toh(42);
    //@ assert BYTE_ORDER == BIG_ENDIAN ==> result == (42LL << 24);
    //@ assert BYTE_ORDER == LITTLE_ENDIAN ==> result == 42;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
