#include "../../../test_common.h"
#include <fts.h>

void runSuccess() {
    char* argv[] = {anystring(), anystring(), NULL};
    //@ assert \exists int i; (argv[i] == \null);
    FTS* fts = fts_open(argv, anyint(), NULL);
    if (fts != NULL) {
        fts_read(fts);
    }
}

void runFailure() {
    fts_read(NULL);
}

int f;
void testValues() {
    f = 2;
    
    char* argv[] = {anystring(), anystring(), NULL};
    //@ assert \exists int i; (argv[i] == \null);
    FTS* fts = fts_open(argv, anyint(), NULL);
    if (fts != NULL) {
        FTSENT* ftsent = fts_read(fts);
        //@ assert ftsent != \null ==> ftsent->fts_level > -1;
        //@ assert ftsent != \null ==> ftsent->fts_number == 0;
        //@ assert ftsent != \null ==> valid_string(ftsent->fts_path);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
