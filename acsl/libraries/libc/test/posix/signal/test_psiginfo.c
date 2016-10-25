#include "../../../test_common.h"
#include <signal.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern siginfo_t * anyinfo();

void runSuccess() {
    psiginfo(anyinfo(), NULL);
}

void runSuccess1() {
    char buf[] = "head";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    psiginfo(anyinfo(), buf);
}

void runFailure() {
    psiginfo(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    psiginfo(anyinfo(), NULL);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
