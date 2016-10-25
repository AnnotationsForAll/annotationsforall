#include "../../../stdio_common.h"
#include <mntent.h>

void runSuccess() {
    FILE* ent = setmntent(anystring(), anystring());
    if (ent == NULL) return;
    endmntent(ent);
}

void runFailure() {
    endmntent(NULL);
}

int f;
void testValues() {
    f = 2;
    
    FILE* ent = setmntent(anystring(), anystring());
    if (ent == NULL) return;
    endmntent(ent);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
