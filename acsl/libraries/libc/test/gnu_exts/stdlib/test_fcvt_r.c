#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    int d,n;
    char buf[10];
    fcvt_r(anydouble(), anyint(), &d, &n, buf, 10);
}

void runFailure() {
    int d,n;
    char buf[10];
    fcvt_r(anydouble(), anyint(), NULL, &n, buf, 10);
}

void runFailure1() {
    int d,n;
    char buf[10];
    fcvt_r(anydouble(), anyint(), &d, NULL, buf, 10);
}

void runFailure2() {
    int d,n;
    char buf[10];
    fcvt_r(anydouble(), anyint(), &d, &n, NULL, 10);
}

void runFailure3() {
    int d,n;
    char buf[10];
    fcvt_r(anydouble(), anyint(), &d, &n, buf, 20);
}

int f;
void testValues() {
    f = 2;
    
    int d,n;
    char buf[10];
    fcvt_r(anydouble(), anyint(), &d, &n, buf, 10);
    //@ assert \valid(buf);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
