#include "../../../test_common.h"
#include <grp.h>

//@ assigns \result \from \nothing;
extern gid_t anygid();

void runSuccess() {
    setgroups(0, NULL);
}

void runSuccess1() {
    gid_t gids[] = {anygid()};
    setgroups(1, gids);
}

void runSuccess2() {
    gid_t gids[] = {anygid(),anygid(),anygid()};
    setgroups(3, gids);
}

void runFailure() {
    setgroups(3, NULL);
}

void runFailure1() {
    gid_t gids[] = {anygid()};
    setgroups(3, gids);
}

int f;
void testValues() {
    f = 2;

    gid_t gids[] = {anygid(),anygid(),anygid()};
    setgroups(3, gids);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
