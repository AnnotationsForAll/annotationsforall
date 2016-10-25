#include "../../../test_common.h"
#include <strings.h>

void runSuccess() {
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    rindex(buf, '?');
    rindex(buf, '\0');
}

void runFailure() {
    rindex(NULL, 'H');
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    char buf[] = "str";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    result = rindex(buf, 't');
    //@ assert result != \null ==> (\base_addr(result) == \base_addr(buf));
    //@ assert result != \null ==> *result == 't';
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
