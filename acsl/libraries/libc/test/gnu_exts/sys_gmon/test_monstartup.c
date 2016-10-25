#include "../../../test_common.h"
#include <sys/gmon.h>

void runSuccess() {
    monstartup(anylong(), anylong());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    monstartup(anylong(), anylong());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
