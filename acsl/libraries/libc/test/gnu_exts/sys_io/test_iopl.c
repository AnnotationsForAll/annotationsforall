#include "../../../test_common.h"
#include <sys/io.h>

void runSuccess() {
    iopl(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    iopl(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
