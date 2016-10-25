#include "../../../test_common.h"
#include <netdb.h>
#include <stdint.h>

void runSuccess() {
    char buf[] = "net";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    getservbyname(buf, buf);
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    struct servent * result;
    
    char buf[] = "net";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = getservbyname(buf, buf);
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
