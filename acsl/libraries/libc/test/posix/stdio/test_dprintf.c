#include "../../../stdio_common.h"

void runSuccess() {
    char buf[] = "%s";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    dprintf(anyint(), buf, "Hello");
}

void runFailure() {
    dprintf(anyint(), NULL, "Hello");
}

int f;
void testValues() {
    f = 2;
    int result;
    
    char buf[] = "%s";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    result = dprintf(anyint(), buf, "Hello");
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
