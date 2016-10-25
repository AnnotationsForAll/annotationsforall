#include "../../../test_common.h"
#include <string.h>

void runSuccess() {
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    memfrob(buf, 5);
}

void runFailure() {
    memfrob(NULL, anysize());
}

void runFailure1() {
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    memfrob(buf, 30);
}

int f;
void testValues() {
    f = 2;
    
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    char* result = memfrob(buf, 5);
    //@ assert result == buf;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
