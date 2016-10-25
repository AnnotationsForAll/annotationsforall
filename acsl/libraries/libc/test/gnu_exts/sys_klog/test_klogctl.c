#include "../../../test_common.h"
#include <sys/klog.h>

void runSuccess() {
    char buf[10];
    klogctl(anyint(), buf, 10);
}

void runSuccess1() {
    klogctl(1, NULL, anyint());
}

void runFailure() {
    char buf[10];
    klogctl(anyint(), NULL, 10);
}

void runFailure1() {
    char buf[10];
    klogctl(anyint(), buf, 20);
}

int f;
void testValues() {
    f = 2;
    
    char buf[10];
    klogctl(anyint(), buf, 10);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
