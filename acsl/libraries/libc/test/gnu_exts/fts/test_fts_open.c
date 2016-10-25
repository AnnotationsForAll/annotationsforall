#include "../../../test_common.h"
#include <fts.h>

void runSuccess() {
    char* argv[] = {anystring(), anystring(), NULL};
    //@ assert \exists int i; (argv[i] == \null);
    fts_open(argv, anyint(), NULL);
}

void runFailure() {
    fts_open(NULL, anyint(), NULL);
}

void runFailure1() {
    char* argv[] = {anystring(), anystring()};
    fts_open(argv, anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    char* argv[] = {anystring(), anystring(), NULL};
    //@ assert \exists int i; (argv[i] == \null);
    fts_open(argv, anyint(), NULL);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
