#include "../../../test_common.h"
#include <wordexp.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern wordexp_t * anyword();

void runSuccess() {
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    wordexp(buf, anyword(), anyint());
}

void runFailure() {
    wordexp(NULL, anyword(), anyint());
}

void runFailure1() {
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    wordexp(buf, NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = wordexp(buf, anyword(), anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
