#include "../../../test_common.h"
#include <unistd.h>

/*@
assigns \result;
*/
extern uid_t anyuid();

/*@
assigns \result;
*/
extern gid_t anygid();

void runSuccess() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    lchown(buf, anyuid(), anygid());
}

void runFailure() {
    lchown(NULL, anyuid(), anygid());
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = lchown(buf, anyuid(), anygid());
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
