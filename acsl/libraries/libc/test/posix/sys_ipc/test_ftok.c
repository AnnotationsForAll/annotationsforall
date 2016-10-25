#include "../../../test_common.h"
#include <sys/ipc.h>

/*@
assigns \result;
ensures \result % 255 != 0;
*/
extern int nonzero();

void runSuccess() {
    char buf[] = "path";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    ftok(buf, nonzero());
}

void runFailure() {
    ftok(NULL, nonzero());
}

int f;
void testValues() {
    f = 2;
    key_t result;
    char buf[] = "path";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    ftok(buf, nonzero());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
