#include "../../../test_common.h"
#include <syslog.h>

void runSuccess() {
    char buf[] = "ident";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    openlog(buf, anyint(), anyint());
}

void runFailure() {
    openlog(NULL, anyint(), anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "ident";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    openlog(buf, anyint(), anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
