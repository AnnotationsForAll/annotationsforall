#include "../../../stdio_common.h"
#include <mntent.h>

void runSuccess() {
    FILE* ent = setmntent(anystring(), anystring());
    if (ent == NULL) return;
    struct mntent * m = getmntent(ent);
    if (m != NULL) {
        hasmntopt(m, anystring());
    }
}

void runFailure() {
    hasmntopt(NULL, anystring());
}

void runFailure1() {
    FILE* ent = setmntent(anystring(), anystring());
    if (ent == NULL) return;
    struct mntent * m = getmntent(ent);
    if (m != NULL) {
        hasmntopt(m, NULL);
    }
}

int f;
void testValues() {
    f = 2;
    
    FILE* ent = setmntent(anystring(), anystring());
    if (ent == NULL) return;
    struct mntent * m = getmntent(ent);
    if (m != NULL) {
        hasmntopt(m, anystring());
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
