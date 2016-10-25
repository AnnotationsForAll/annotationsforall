#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    char buf[] = "temp";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    mktemp(buf);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    char buf[] = "temp";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    char* result = mktemp(buf);
    //@ assert result == \null || \valid(result);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
