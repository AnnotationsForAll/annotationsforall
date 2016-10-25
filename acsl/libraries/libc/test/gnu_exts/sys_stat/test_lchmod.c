#include "../../../test_common.h"
#include <sys/stat.h>

/*@
assigns \result;
*/
extern mode_t anymode();

void runSuccess() {
    char buf[] = "f";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    lchmod(buf, anymode());
}

void runFailure() {
    lchmod(NULL, anymode());
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "f";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = lchmod(buf, anymode());
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
