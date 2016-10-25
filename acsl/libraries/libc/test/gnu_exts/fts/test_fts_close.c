#include "../../../test_common.h"
#include <fts.h>

void runSuccess() {
    char* argv[] = {anystring(), anystring(), NULL};
    //@ assert \exists int i; (argv[i] == \null);
    FTS* fts = fts_open(argv, anyint(), NULL);
    if (fts != NULL) {
        fts_close(fts);
    }
}

void runFailure() {
    fts_close(NULL);
}

void runFailure1() {
    char* argv[] = {anystring(), anystring(), NULL};
    //@ assert \exists int i; (argv[i] == \null);
    FTS* fts = fts_open(argv, anyint(), NULL);
    if (fts != NULL) {
        fts_close(fts);
        fts_close(fts);
    }
}

int f;
void testValues() {
    f = 2;
    
    char* argv[] = {anystring(), anystring(), NULL};
    //@ assert \exists int i; (argv[i] == \null);
    FTS* fts = fts_open(argv, anyint(), NULL);
    if (fts != NULL) {
        fts_close(fts);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
