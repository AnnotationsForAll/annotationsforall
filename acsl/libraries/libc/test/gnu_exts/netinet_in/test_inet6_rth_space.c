#include "../../../test_common.h"
#include <netinet/in.h>

void runSuccess() {
    inet6_rth_space(anyint(), anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    inet6_rth_space(anyint(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
