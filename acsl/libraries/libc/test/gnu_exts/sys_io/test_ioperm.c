#include "../../../test_common.h"
#include <sys/io.h>

void runSuccess() {
    ioperm(anylong(), anylong(), anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    ioperm(anylong(), anylong(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
