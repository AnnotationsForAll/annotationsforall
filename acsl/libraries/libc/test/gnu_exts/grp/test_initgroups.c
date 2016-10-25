#include "../../../test_common.h"
#include <grp.h>

//@ assigns \result \from \nothing;
extern gid_t anygid();

void runSuccess() {
    initgroups(anystring(), anygid());
}

void runFailure() {
    initgroups(NULL, anygid());
}

int f;
void testValues() {
    f = 2;

    initgroups(anystring(), anygid());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
