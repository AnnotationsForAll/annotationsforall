#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    double buf[3];
    getloadavg(buf, 3);
}

void runSuccess1() {
    double buf[6];
    getloadavg(buf, 3);
}

void runSuccess2() {
    double buf[1];
    getloadavg(buf, 1);
}

void runSuccess3() {
    double buf[3];
    getloadavg(buf, 1);
}

void runSuccess4() {
    double buf[3];
    getloadavg(buf, 3000);
}

void runFailure() {
    getloadavg(NULL, 3);
}

void runFailure1() {
    double buf[1];
    getloadavg(buf, 3);
}

int f;
void testValues() {
    f = 2;
    
    double buf[3];
    getloadavg(buf, 3);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
