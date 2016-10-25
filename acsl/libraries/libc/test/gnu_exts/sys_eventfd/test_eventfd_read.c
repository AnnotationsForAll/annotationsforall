#include "../../../test_common.h"
#include <sys/eventfd.h>

void runSuccess() {
    eventfd_t v;
    eventfd_read(anyint(), &v);
}

void runFailure() {
    eventfd_t v;
    eventfd_read(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    eventfd_t v;
    eventfd_read(anyint(), &v);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
