#include "../../../test_common.h"
#include <fts.h>

void runSuccess() {
    char* argv[] = {anystring(), anystring(), NULL};
    //@ assert \exists int i; (argv[i] == \null);
    FTS* fts = fts_open(argv, anyint(), NULL);
    if (fts != NULL) {
        FTSENT* ftsent = fts_read(fts);
        if (ftsent != NULL) {
            fts_set(fts, ftsent, anyint());
        }
    }
}

void runFailure() {
    char* argv[] = {anystring(), anystring(), NULL};
    //@ assert \exists int i; (argv[i] == \null);
    FTS* fts = fts_open(argv, anyint(), NULL);
    if (fts != NULL) {
        FTSENT* ftsent = fts_read(fts);
        if (ftsent != NULL) {
            fts_set(NULL, ftsent, anyint());
        }
    }
}

void runFailure1() {
    char* argv[] = {anystring(), anystring(), NULL};
    //@ assert \exists int i; (argv[i] == \null);
    FTS* fts = fts_open(argv, anyint(), NULL);
    if (fts != NULL) {
        FTSENT* ftsent = fts_read(fts);
        if (ftsent != NULL) {
            fts_set(fts, NULL, anyint());
        }
    }
}

int f;
void testValues() {
    f = 2;
    
    char* argv[] = {anystring(), anystring(), NULL};
    //@ assert \exists int i; (argv[i] == \null);
    FTS* fts = fts_open(argv, anyint(), NULL);
    if (fts != NULL) {
        FTSENT* ftsent = fts_read(fts);
        if (ftsent != NULL) {
            fts_set(fts, ftsent, anyint());
        }
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
