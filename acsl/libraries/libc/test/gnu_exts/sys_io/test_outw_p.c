#include "../../../test_common.h"
#include <sys/io.h>

/*@ assigns \result; */
unsigned short anyport();

void runSuccess() {
    if(!iopl(3)) {
        unsigned short x;
        outw_p(x, anyport());
    }
}

void runFailure() {
    unsigned short x;
    outw_p(x, anyport());
}

int f;
void testValues() {
    f = 2;
    
    if(!iopl(3)) {
        unsigned short x;
        outw_p(x, anyport());
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
