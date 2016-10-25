#include "../../../test_common.h"
#include <sys/quota.h>

void runSuccess() {
    caddr_t addr;
    quotactl(anyint(), anystring(), anyint(), addr);
}

void runFailure() {
    caddr_t addr;
    quotactl(anyint(), NULL, anyint(), addr);
}

int f;
void testValues() {
    f = 2;
    
    caddr_t addr;
    quotactl(anyint(), anystring(), anyint(), addr);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
