#include "../../../test_common.h"
#include <grp.h>

void runSuccess() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    getgrnam(buf);
}

void runFailure() {
    getgrnam(NULL);
}

int f;
void testValues() {
    f = 2;
    struct group * result;
    
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = getgrnam(buf);
    //@ assert result != \null ==> \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
