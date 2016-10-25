#include "../../../stdio_common.h"
#include <stdio.h>

void runSuccess() {
    fcloseall();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    fcloseall();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
