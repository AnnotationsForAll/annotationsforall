#include "../../../test_common.h"
#include <gshadow.h>

void runSuccess() {
    struct sgrp sg;
    char buf[10];
    struct sgrp * p;
    getsgent_r(&sg, buf, 10, &p);
}

void runFailure() {
    struct sgrp sg;
    char buf[10];
    struct sgrp * p;
    getsgent_r(NULL, buf, 10, &p);
}

void runFailure1() {
    struct sgrp sg;
    char buf[10];
    struct sgrp * p;
    getsgent_r(&sg, NULL, anysize(), &p);
}

void runFailure2() {
    struct sgrp sg;
    char buf[10];
    struct sgrp * p;
    getsgent_r(&sg, buf, 10, NULL);
}

void runFailure3() {
    struct sgrp sg;
    char buf[10];
    struct sgrp * p;
    getsgent_r(&sg, buf, 20, &p);
}

int f;
void testValues() {
    f = 2;
    struct sgrp * result;
    
    struct sgrp sg;
    char buf[10];
    struct sgrp * p;
    getsgent_r(&sg, buf, 10, &p);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
