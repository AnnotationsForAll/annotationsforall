#include "../../../test_common.h"
#include <gshadow.h>

void runSuccess() {
    struct sgrp sg;
    char buf[10];
    struct sgrp * p;
    getsgnam_r(anystring(), &sg, buf, 10, &p);
}

void runFailure() {
    struct sgrp sg;
    char buf[10];
    struct sgrp * p;
    getsgnam_r(anystring(), NULL, buf, 10, &p);
}

void runFailure1() {
    struct sgrp sg;
    char buf[10];
    struct sgrp * p;
    getsgnam_r(anystring(), &sg, NULL, anysize(), &p);
}

void runFailure2() {
    struct sgrp sg;
    char buf[10];
    struct sgrp * p;
    getsgnam_r(anystring(), &sg, buf, 10, NULL);
}

void runFailure3() {
    struct sgrp sg;
    char buf[10];
    struct sgrp * p;
    getsgnam_r(anystring(), &sg, buf, 20, &p);
}

void runFailure4() {
    struct sgrp sg;
    char buf[10];
    struct sgrp * p;
    getsgnam_r(NULL, &sg, buf, 10, &p);
}

int f;
void testValues() {
    f = 2;
    struct sgrp * result;
    
    struct sgrp sg;
    char buf[10];
    struct sgrp * p;
    getsgnam_r(anystring(), &sg, buf, 10, &p);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
