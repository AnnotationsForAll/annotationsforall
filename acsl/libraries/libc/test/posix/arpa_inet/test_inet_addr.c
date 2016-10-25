#include "../../../test_common.h"
#include <arpa/inet.h>
#include <stdint.h>

void runSuccess() {
    char buf[] = "1.2.3.4";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    inet_addr(buf);
}

void runSuccess1() {
    char buf[] = "?";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    inet_addr(buf);
}

void runFailure() {
    inet_addr(NULL);
}

int f;
void testValues() {
    f = 2;
    in_addr_t result;
    char buf[] = "1.2.3.4";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    inet_addr(buf);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
