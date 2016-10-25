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

    dbm_fetch(db, anydatum());
}

void runFailure() {
    dbm_fetch(NULL, anydatum());
}

int f;
void testValues() {
    f = 2;
    datum result;
    char buf[] = "file";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    DBM* db = dbm_open(buf, O_RDWR, S_IRUSR);
    if (db == NULL) {return;}
    
    result = dbm_fetch(db, anydatum());
    //@ assert result.dptr == \null || \valid((char*)result.dptr);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
