#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    group_member(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    group_member(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
