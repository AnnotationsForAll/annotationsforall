#include "../../../test_common.h"
#include <ndbm.h>
#include <fcntl.h>

/*@
assigns \result;
*/
extern datum anydatum();

void runSuccess() {
    char buf[] = "file";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    DBM* db = dbm_open(buf, O_RDWR, S_IRUSR);
    if (db == NULL) {return;}

    dbm_store(db, anydatum(), anydatum(), DBM_INSERT);
}

void runSuccess1() {
    char buf[] = "file";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    DBM* db = dbm_open(buf, O_RDWR, S_IRUSR);
    if (db == NULL) {return;}

    dbm_store(db, anydatum(), anydatum(), DBM_REPLACE);
}

void runFailure() {
    dbm_store(NULL, anydatum(), anydatum(), DBM_REPLACE);
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
    
    dbm_store(db, anydatum(), anydatum(), DBM_INSERT);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
