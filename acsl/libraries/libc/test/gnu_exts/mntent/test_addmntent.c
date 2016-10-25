#include "../../../stdio_common.h"
#include <mntent.h>

void runSuccess() {
    FILE* ent = setmntent(anystring(), anystring());
    if (ent == NULL) return;
    struct mntent m;
    addmntent(ent, &m);
}

void runFailure() {
    FILE* ent = setmntent(anystring(), anystring());
    if (ent == NULL) return;
    addmntent(ent, NULL);
}

void runFailure1() {
    struct mntent m;
    addmntent(NULL, &m);
}

int f;
void testValues() {
    f = 2;
    
    FILE* ent = setmntent(anystring(), anystring());
    if (ent == NULL) return;
    struct mntent m;
    addmntent(ent, &m);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
