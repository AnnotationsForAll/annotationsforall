#include "../../test_common.h"
#include <string.h>

void runSuccess() {
    char s[] = "Hello";
    //@ assert \valid(s+(0..\block_length(s)-1));
    memchr(s, '?', 6);
    memchr(s, '\0', 6);
}

void runFailure() {
    memchr(NULL, 'H', 30); 
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    char buf[] = "string";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    result = memchr(buf, 't', 6);
    //@ assert result != \null ==> (\base_addr(result) == \base_addr(buf));
    //@ assert result != \null ==> *result == 't';
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
