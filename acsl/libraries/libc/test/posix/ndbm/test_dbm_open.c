#include "../../../test_common.h"
#include <ndbm.h>
#include <fcntl.h>

void runSuccess() {
    char buf[] = "file";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    dbm_open(buf, O_RDWR, S_IRUSR);
}

void runFailure() {
    dbm_open(NULL, O_RDWR, S_IRUSR);
}

int f;
void testValues() {
    f = 2;
    DBM* result;
    
    char buf[] = "file";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = dbm_open(buf, O_RDWR, S_IRUSR);
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
