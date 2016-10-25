#include "../../../test_common.h"
#include <gshadow.h>

void runSuccess() {
    getsgent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    struct sgrp * result;
    
    result = getsgent();
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
