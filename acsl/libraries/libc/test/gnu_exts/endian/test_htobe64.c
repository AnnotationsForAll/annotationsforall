#include "../../../test_common.h"
#include <endian.h>

void runSuccess() {
    htobe64((uint64_t)anylonglong());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    uint64_t result;

    result = htobe64(0);
    //@ assert result == 0;

    result = htobe64(1);
    //@ assert BYTE_ORDER == LITTLE_ENDIAN ==> result == (1LL << 56);
    //@ assert BYTE_ORDER == BIG_ENDIAN ==> result == 1;

    result = htobe64(42);
    //@ assert BYTE_ORDER == LITTLE_ENDIAN ==> result == (42LL << 56);
    //@ assert BYTE_ORDER == BIG_ENDIAN ==> result == 42;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
