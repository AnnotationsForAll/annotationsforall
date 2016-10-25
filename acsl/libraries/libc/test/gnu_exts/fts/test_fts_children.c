#include "../../../test_common.h"
#include <fts.h>

void runSuccess() {
    char* argv[] = {anystring(), anystring(), NULL};
    //@ assert \exists int i; (argv[i] == \null);
    FTS* fts = fts_open(argv, anyint(), NULL);
    if (fts != NULL) {
        fts_children(fts, anyint());
    }
}

void runFailure() {
    fts_children(NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    
    char* argv[] = {anystring(), anystring(), NULL};
    //@ assert \exists int i; (argv[i] == \null);
    FTS* fts = fts_open(argv, anyint(), NULL);
    if (fts != NULL) {
        FTSENT* ftsent = fts_children(fts, anyint());
        //@ assert ftsent != \null ==> ftsent->fts_level > -1;
        //@ assert ftsent != \null ==> ftsent->fts_number == 0;
        //@ assert ftsent != \null ==> valid_string(ftsent->fts_path);
        //@ assert ftsent != \null ==> ftsent->fts_link == \null || \valid(ftsent->fts_link);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
