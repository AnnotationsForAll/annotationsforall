//OPTIONS: -wp-model Typed+cast

#include "../../../test_common.h"
#include <sys/io.h>

/*@ assigns \result; */
unsigned short anyport();

void runSuccess() {
    if(!iopl(3)) {
        unsigned short buf[10];
        outsw(anyport(), buf, 10);
    }
}

void runFailure() {
    unsigned short buf[10];
    outsw(anyport(), buf, 10);
}

void runFailure1() {
    if(!iopl(3)) {
        unsigned short buf[10];
        outsw(anyport(), buf, 20);
    }
}

int f;
void testValues() {
    f = 2;
    
    if(!iopl(3)) {
        unsigned short buf[10];
        outsw(anyport(), buf, 10);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
