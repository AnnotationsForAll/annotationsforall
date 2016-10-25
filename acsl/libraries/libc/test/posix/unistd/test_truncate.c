#include "../../../test_common.h"
#include <unistd.h>

/*@
assigns \result;
*/
extern off_t anyoff();

void runSuccess() {
    char buf[] = "path";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    truncate(buf, anyoff());
}

void runFailure() {
    truncate(NULL, anyoff());
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "path";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = truncate(buf, anyoff());
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
