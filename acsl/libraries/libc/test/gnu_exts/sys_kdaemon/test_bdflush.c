#include "../../../test_common.h"
#include <sys/io.h>

void runSuccess() {
    bdflush(anyint(), anylong());
}

void runSuccess1() {
    long x;
    bdflush(anyint(), &x);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    bdflush(anyint(), anylong());

    long x;
    bdflush(anyint(), &x);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
