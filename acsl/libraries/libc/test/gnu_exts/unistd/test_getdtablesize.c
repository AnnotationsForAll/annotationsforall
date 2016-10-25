#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    getdtablesize();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    int result = getdtablesize();
    //@ assert result >= 20;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
