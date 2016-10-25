#include "../../../test_common.h"
#include <sys/eventfd.h>

void runSuccess() {
    eventfd_t v;
    eventfd_write(anyint(), v);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    eventfd_t v;
    eventfd_write(anyint(), v);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
