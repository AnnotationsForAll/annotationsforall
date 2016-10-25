#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    char buf[10];
    confstr(anyint(), buf, 10);
}

void runFailure() {
    char buf[10];
    confstr(anyint(), buf, 20);
}

void runFailure1() {
    confstr(anyint(), NULL, 10);
}

int f;
void testValues() {
    f = 2;
    size_t result;
    
    char buf[10];
    confstr(anyint(), buf, 10);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
