#include "../../../test_common.h"
#include <endian.h>

void runSuccess() {
    htole64((uint64_t)anylonglong());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    uint64_t result;

    result = htole64(0);
    //@ assert result == 0;

    result = htole64(1);
    //@ assert BYTE_ORDER == BIG_ENDIAN ==> result == (1LL << 56);
    //@ assert BYTE_ORDER == LITTLE_ENDIAN ==> result == 1;

    result = htole64(42);
    //@ assert BYTE_ORDER == BIG_ENDIAN ==> result == (42LL << 56);
    //@ assert BYTE_ORDER == LITTLE_ENDIAN ==> result == 42;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
