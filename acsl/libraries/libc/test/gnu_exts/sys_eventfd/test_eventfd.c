#include "../../../test_common.h"
#include <sys/eventfd.h>

void runSuccess() {
    eventfd(anyuint(), anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    eventfd(anyuint(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
