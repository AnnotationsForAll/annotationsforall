#include "../../../test_common.h"
#include <sys/stat.h>

void runSuccess() {
    getumask();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    getumask();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
