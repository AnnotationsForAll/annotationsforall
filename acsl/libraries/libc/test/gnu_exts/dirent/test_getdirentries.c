#include "../../../test_common.h"
#include <dirent.h>

void runSuccess() {
    off_t p = 0;
    char buf[10];
    getdirentries(anyint(), buf, 10, &p);
}

void runFailure() {
    off_t p = 0;
    char buf[10];
    getdirentries(anyint(), NULL, anyint(), &p);
}

void runFailure1() {
    off_t p = 0;
    char buf[10];
    getdirentries(anyint(), buf, 10, NULL);
}

void runFailure2() {
    off_t p = 0;
    char buf[10];
    getdirentries(anyint(), buf, 20, &p);
}

void runFailure3() {
    off_t p = 20;
    char buf[10];
    getdirentries(anyint(), buf, 10, &p);
}

int f;
void testValues() {
    f = 2;
    
    off_t p = 0;
    char buf[10];
    getdirentries(anyint(), buf, 10, &p);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
