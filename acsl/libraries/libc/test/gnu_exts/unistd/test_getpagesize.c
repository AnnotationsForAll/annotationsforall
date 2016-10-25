#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    getpagesize();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    int result = getpagesize();
    //@ assert result > 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
