#include "../../../test_common.h"
#include <sys/gmon.h>

void runSuccess() {
    moncontrol(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    moncontrol(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
