#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    char *a, *b, *c;
    getnetgrent(&a, &b, &c);
}

void runFailure() {
    char *a, *b, *c;
    getnetgrent(NULL, &b, &c);
}

void runFailure1() {
    char *a, *b, *c;
    getnetgrent(&a, NULL, &c);
}

void runFailure2() {
    char *a, *b, *c;
    getnetgrent(&a, &b, NULL);
}

int f;
void testValues() {
    f = 2;
    
    char *a, *b, *c;
    getnetgrent(&a, &b, &c);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
