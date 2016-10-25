#include "../../../test_common.h"
#include <regex.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern regex_t * anyregex();

void runSuccess() {
    char buf[] = "pat";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    regcomp(anyregex(), buf, anyint());
}

void runFailure() {
    char buf[] = "pat";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    regcomp(NULL, buf, anyint());
}

void runFailure1() {
    regcomp(anyregex(), NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    regex_t* p = anyregex();
    
    char buf[] = "pat";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = regcomp(anyregex(), buf, anyint());
    //@ assert result == 0 ==> \valid_read(p);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
