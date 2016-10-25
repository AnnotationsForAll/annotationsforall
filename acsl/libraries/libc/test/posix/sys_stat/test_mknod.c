#include "../../../test_common.h"
#include <sys/stat.h>

/*@
assigns \result;
*/
extern mode_t anymode();

/*@
assigns \result;
*/
extern dev_t anydev();

void runSuccess() {
    char buf[] = "f";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    mknod(buf, anymode(), anydev());
}

void runFailure() {
    mknod(NULL, anymode(), anydev());
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "f";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = mknod(buf, anymode(), anydev());
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
