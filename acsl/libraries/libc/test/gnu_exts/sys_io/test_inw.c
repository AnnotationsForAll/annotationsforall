#include "../../../test_common.h"
#include <sys/io.h>

/*@ assigns \result; */
unsigned short anyport();

void runSuccess() {
    if(!iopl(3)) {
        inw(anyport());
    }
}

void runFailure() {
    inw(anyport());
}

int f;
void testValues() {
    f = 2;
    
    if(!iopl(3)) {
        inw(anyport());
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
