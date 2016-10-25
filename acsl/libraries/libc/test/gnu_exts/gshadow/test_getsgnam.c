#include "../../../test_common.h"
#include <gshadow.h>

void runSuccess() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    getsgnam(buf);
}

void runFailure() {
    getsgnam(NULL);
}

int f;
void testValues() {
    f = 2;
    struct sgrp * result;
    
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = getsgnam(buf);
    //@ assert result != \null ==> \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
