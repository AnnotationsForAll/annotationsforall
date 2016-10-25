#include "../../../test_common.h"
#include <sys/vtimes.h>

void runSuccess() {
    vtimes(NULL, NULL);
}

void runSuccess1() {
    struct vtimes vm;
    vtimes(&vm, NULL);
}

void runSuccess2() {
    struct vtimes vm;
    vtimes(NULL, &vm);
}

void runSuccess3() {
    struct vtimes vm1;
    struct vtimes vm2;
    vtimes(&vm1, &vm2);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    struct vtimes vm1;
    struct vtimes vm2;
    vtimes(&vm1, &vm2);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
