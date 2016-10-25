#include "../../../test_common.h"
#include <stropts.h>

void runSuccess() {
    char buf[] = "s";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    fattach(anyint(), buf);
}

void runFailure() {
    fattach(anyint(), NULL);
}

void runFailure1() {
    char buf[10];
    fattach(anyint(), buf);
}

int f;
void testValues() {
    f = 2;
    char buf[] = "s";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    fattach(anyint(), buf);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
