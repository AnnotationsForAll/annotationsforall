#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    getnetbyaddr((uint32_t)anylonglong(), anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    getnetbyaddr((uint32_t)anylonglong(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
