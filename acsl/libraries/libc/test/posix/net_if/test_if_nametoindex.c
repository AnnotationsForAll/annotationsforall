#include "../../../test_common.h"
#include <net/if.h>

void runSuccess() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    if_nametoindex(buf);
}

void runFailure() {
    if_nametoindex(NULL);
}

int f;
void testValues() {
    f = 2;
    unsigned int result;
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    if_nametoindex(buf);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
