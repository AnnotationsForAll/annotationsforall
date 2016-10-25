#include "../../../stdio_common.h"
#include <stdio_ext.h>

void runSuccess() {
    _flushlbf();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    _flushlbf();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
