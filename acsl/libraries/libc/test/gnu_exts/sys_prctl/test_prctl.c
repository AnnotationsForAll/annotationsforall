#include "../../../test_common.h"
#include <sys/prctl.h>

void runSuccess() {
    prctl(anyint(), anyulong(), anyulong(), anyulong(), anyulong());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    prctl(anyint(), anyulong(), anyulong(), anyulong(), anyulong());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
