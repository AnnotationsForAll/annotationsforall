#include "../../../test_common.h"
#include <ndbm.h>
#include <fcntl.h>

void runSuccess() {
    char buf[] = "file";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    DBM* db = dbm_open(buf, O_RDWR, S_IRUSR);
    if (db == NULL) {return;}

    dbm_error(db);
}

void runFailure() {
    dbm_error(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "file";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    DBM* db = dbm_open(buf, O_RDWR, S_IRUSR);
    if (db == NULL) {return;}
    
    result = dbm_error(db);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
