#include "../../../test_common.h"
#include <ndbm.h>
#include <fcntl.h>

void runSuccess() {
    char buf[] = "file";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    DBM* db = dbm_open(buf, O_RDWR, S_IRUSR);
    if (db == NULL) {return;}

    dbm_close(db);
}

void runFailure() {
    dbm_close(NULL);
}

int f;
void testValues() {
    f = 2;
    char buf[] = "file";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    DBM* p = dbm_open(buf, O_RDWR, S_IRUSR);
    if (p == NULL) {return;}
    
    dbm_close(p);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
