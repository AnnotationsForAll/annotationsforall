#include "../../../test_common.h"
#include <grp.h>

void runSuccess() {
    struct group sg;
    char buf[10];
    struct group * p;
    getgrent_r(&sg, buf, 10, &p);
}

void runFailure() {
    struct group sg;
    char buf[10];
    struct group * p;
    getgrent_r(NULL, buf, 10, &p);
}

void runFailure1() {
    struct group sg;
    char buf[10];
    struct group * p;
    getgrent_r(&sg, NULL, anysize(), &p);
}

void runFailure2() {
    struct group sg;
    char buf[10];
    struct group * p;
    getgrent_r(&sg, buf, 10, NULL);
}

void runFailure3() {
    struct group sg;
    char buf[10];
    struct group * p;
    getgrent_r(&sg, buf, 20, &p);
}

int f;
void testValues() {
    f = 2;
    struct group * result;
    
    struct group sg;
    char buf[10];
    struct group * p;
    getgrent_r(&sg, buf, 10, &p);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
