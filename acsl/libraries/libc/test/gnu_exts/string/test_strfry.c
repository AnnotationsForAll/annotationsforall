#include "../../../test_common.h"
#include <string.h>

void runSuccess() {
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    strfry(buf);
}

void runFailure() {
    strfry(NULL);
}

int f;
void testValues() {
    f = 2;
    
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    char* result = strfry(buf);
    //@ assert result == buf;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
