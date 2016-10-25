#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    dup3(anyint(), anyint(), anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    dup3(anyint(), anyint(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
