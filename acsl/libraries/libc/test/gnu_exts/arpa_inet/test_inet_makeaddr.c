#include "../../../test_common.h"
#include <arpa/inet.h>

void runSuccess() {
    inet_makeaddr((uint32_t)anylonglong(), (uint32_t)anylonglong());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    inet_makeaddr((uint32_t)anylonglong(), (uint32_t)anylonglong());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
