#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    char *a, *b, *c;
    char buf[10];
    getnetgrent_r(&a, &b, &c, buf, 10);
}

void runFailure() {
    char *a, *b, *c;
    char buf[10];
    getnetgrent_r(NULL, &b, &c, buf, 10);
}

void runFailure1() {
    char *a, *b, *c;
    char buf[10];
    getnetgrent_r(&a, NULL, &c, buf, 10);
}

void runFailure2() {
    char *a, *b, *c;
    char buf[10];
    getnetgrent_r(&a, &b, NULL, buf, 10);
}

void runFailure3() {
    char *a, *b, *c;
    char buf[10];
    getnetgrent_r(&a, &b, &c, NULL, anysize());
}

void runFailure4() {
    char *a, *b, *c;
    char buf[10];
    getnetgrent_r(&a, &b, &c, buf, 20);
}

int f;
void testValues() {
    f = 2;
    
    char *a, *b, *c;
    char buf[10];
    getnetgrent_r(&a, &b, &c, buf, 10);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
