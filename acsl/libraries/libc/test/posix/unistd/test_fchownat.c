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
    
    fchownat(anyint(), buf, anyuid(), anygid(), anyint());
}

void runFailure() {
    fchownat(anyint(), NULL, anyuid(), anygid(), anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = fchownat(anyint(), buf, anyuid(), anygid(), anyint());
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
