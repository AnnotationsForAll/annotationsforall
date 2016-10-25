#include "../../../test_common.h"
#include <nl_types.h>
#include <fcntl.h>

void runSuccess() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    catopen(buf, FD_CLOEXEC);
}

void runFailure() {
    catopen(NULL, FD_CLOEXEC);
}

int f;
void testValues() {
    f = 2;
    nl_catd result;
    
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = catopen(buf, FD_CLOEXEC);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
