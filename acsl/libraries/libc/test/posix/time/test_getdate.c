#include "../../../unistd_common.h"
#include <time.h>

void runSuccess() {
    char buf[] = "date";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    getdate(buf);
}

void runFailure() {
    getdate(NULL);
}

int f;
void testValues() {
    f = 2;
    struct tm * result;
    
    char buf[] = "date";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = getdate(buf);
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
