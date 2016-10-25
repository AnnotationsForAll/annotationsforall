#include "../../../test_common.h"
#include <sys/sysctl.h>

void runSuccess() {
    int names[3];
    char old[10];
    char new[5];
    size_t len = 10;
    sysctl(names, 3, old, &len, new, 5);
}

void runSuccess1() {
    int names[3];
    sysctl(names, 3, NULL, NULL, NULL, 5);
}

void runFailure() {
    sysctl(NULL, anyint(), NULL, NULL, NULL, anyint());
}

void runFailure1() {
    int names[3];
    char old[10];
    char new[5];
    int len = 10;
    sysctl(names, 20, old, &len, new, 5);
}

void runFailure2() {
    int names[3];
    char old[10];
    char new[5];
    int len = 20;
    sysctl(names, 3, old, &len, new, 5);
}

void runFailure3() {
    int names[3];
    char old[10];
    char new[5];
    int len = 10;
    sysctl(names, 3, old, &len, new, 20);
}

int f;
void testValues() {
    f = 2;
    
    int names[3];
    char old[10];
    char new[5];
    int len = 10;
    sysctl(names, 3, old, &len, new, 5);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
