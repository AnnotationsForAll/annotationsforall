#include "../../../test_common.h"
#include <grp.h>

//@ assigns \result \from \nothing;
extern gid_t anygid();

void runSuccess() {
    int n = 0;
    getgrouplist(anystring(), anygid(), NULL, &n);
}

void runSuccess1() {
    gid_t gids[] = {anygid()};
    int n = 1;
    getgrouplist(anystring(), anygid(), gids, &n);
}

void runSuccess2() {
    gid_t gids[] = {anygid(),anygid(),anygid()};
    int n = 3;
    getgrouplist(anystring(), anygid(), gids, &n);
}

void runFailure() {
    gid_t gids[] = {anygid()};
    int n = 1;
    getgrouplist(NULL, anygid(), gids, &n);
}

void runFailure1() {
    gid_t gids[] = {anygid()};
    int n = 3;
    getgrouplist(anystring(), anygid(), gids, &n);
}

void runFailure2() {
    gid_t gids[] = {anygid()};
    getgrouplist(anystring(), anygid(), gids, NULL);
}

int f;
void testValues() {
    f = 2;

    gid_t gids[] = {anygid(),anygid(),anygid()};
    int n = 3;
    getgrouplist(anystring(), anygid(), gids, &n);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
