#include "../../../test_common.h"
#include <sys/io.h>

/*@ assigns \result; */
unsigned short anyport();

void runSuccess() {
    if(!iopl(3)) {
        inl_p(anyport());
    }
}

void runFailure() {
    inl_p(anyport());
}

int f;
void testValues() {
    f = 2;
    
    if(!iopl(3)) {
        inl_p(anyport());
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
