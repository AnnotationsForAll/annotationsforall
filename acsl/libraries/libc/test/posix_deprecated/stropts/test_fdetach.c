#include "../../../test_common.h"
#include <stropts.h>

void runSuccess() {
    char buf[] = "s";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    fdetach(buf);
}

void runFailure() {
    fdetach(NULL);
}

void runFailure1() {
    char buf[10];
    fdetach(buf);
}

int f;
void testValues() {
    f = 2;
    char buf[] = "s";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    fdetach(buf);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
